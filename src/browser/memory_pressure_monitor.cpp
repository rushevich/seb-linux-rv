#include "memory_pressure_monitor.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QTimerEvent>

#include <sys/sysinfo.h>

namespace seb::browser {

namespace {
bool readUsedFraction(double *usedFraction, unsigned long long *totalBytes)
{
    if (!usedFraction || !totalBytes) {
        return false;
    }

    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        return false;
    }

    const unsigned long long total =
        static_cast<unsigned long long>(info.totalram) * static_cast<unsigned long long>(info.mem_unit);
    const unsigned long long free =
        static_cast<unsigned long long>(info.freeram) * static_cast<unsigned long long>(info.mem_unit);
    if (!total) {
        return false;
    }

    const unsigned long long used = total > free ? (total - free) : 0;
    *totalBytes = total;
    *usedFraction = static_cast<double>(used) / static_cast<double>(total);
    return true;
}
}  // namespace

MemoryPressureMonitor::MemoryPressureMonitor(QObject *parent)
    : QObject(parent)
{
}

void MemoryPressureMonitor::setThresholdPercent(int percent)
{
    thresholdPercent_ = qBound(1, percent, 99);
}

int MemoryPressureMonitor::thresholdPercent() const
{
    return thresholdPercent_;
}

void MemoryPressureMonitor::start()
{
    if (timerId_) {
        return;
    }
    // Poll at a conservative cadence; we only need to catch sustained pressure.
    timerId_ = startTimer(2000);
}

void MemoryPressureMonitor::stop()
{
    if (!timerId_) {
        return;
    }
    killTimer(timerId_);
    timerId_ = 0;
}

void MemoryPressureMonitor::timerEvent(QTimerEvent *event)
{
    if (event && event->timerId() == timerId_) {
        pollOnce();
    }
    QObject::timerEvent(event);
}

void MemoryPressureMonitor::pollOnce()
{
    double usedFraction = 0.0;
    unsigned long long totalBytes = 0;
    if (!readUsedFraction(&usedFraction, &totalBytes)) {
        return;
    }

    const double threshold = static_cast<double>(thresholdPercent_) / 100.0;
    if (usedFraction >= threshold) {
        emit memoryPressureDetected(usedFraction, totalBytes);
    }
}

}  // namespace seb::browser

