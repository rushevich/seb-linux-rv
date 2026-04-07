#pragma once

#include <QObject>

namespace seb::browser {

class MemoryPressureMonitor final : public QObject
{
    Q_OBJECT

public:
    explicit MemoryPressureMonitor(QObject *parent = nullptr);

    void setThresholdPercent(int percent);
    int thresholdPercent() const;

    void start();
    void stop();

signals:
    void memoryPressureDetected(double usedFraction, unsigned long long totalBytes);

private:
    void timerEvent(QTimerEvent *event) override;
    void pollOnce();

    int thresholdPercent_ = 75;
    int timerId_ = 0;
};

}  // namespace seb::browser

