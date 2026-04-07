#include "wpe_browser_view.h"

#include <QLabel>
#include <QMetaObject>
#include <QVariant>
#include <QUrl>

#if defined(SEB_USE_WPE)
#include <QQuickWidget>
#include <QQmlContext>
#include <QQmlEngine>
#endif

namespace seb::browser::engine {

WPEBrowserView::WPEBrowserView(QWidget *parentWidget, QObject *parent)
    : BrowserView(parent)
{
#if defined(SEB_USE_WPE)
    quickWidget_ = new QQuickWidget(parentWidget);
    quickWidget_->setResizeMode(QQuickWidget::SizeRootObjectToView);

    // QML type is documented as WPEView in module org.wpewebkit.qtwpe.
    // We keep it inline to avoid an extra QML file in early bring-up.
    static const char kWpeQml[] =
        "import QtQuick 2.15\n"
        "import org.wpewebkit.qtwpe 1.0\n"
        "WPEView {\n"
        "  id: wpe\n"
        "}\n";

    quickWidget_->setSource(QUrl(QStringLiteral("data:text/plain,") + QString::fromLatin1(kWpeQml)));
    wpeRootObject_ = quickWidget_->rootObject();

    if (wpeRootObject_) {
        connect(wpeRootObject_, SIGNAL(urlChanged()), this, [this] {
            const QUrl url = wpeRootObject_->property("url").toUrl();
            currentUrl_ = url;
            emit urlChanged(url);
        });
        connect(wpeRootObject_, SIGNAL(titleChanged()), this, [this] {
            const QString title = wpeRootObject_->property("title").toString();
            currentTitle_ = title;
            emit titleChanged(title);
        });
    }
#else
    placeholder_ = new QLabel(QStringLiteral("WPE backend not enabled in this build."), parentWidget);
    placeholder_->setWordWrap(true);
    placeholder_->setMargin(12);
#endif
}

WPEBrowserView::~WPEBrowserView() = default;

QWidget *WPEBrowserView::widget()
{
#if defined(SEB_USE_WPE)
    return quickWidget_;
#else
    return placeholder_;
#endif
}

QUrl WPEBrowserView::url() const
{
    return currentUrl_;
}

QString WPEBrowserView::title() const
{
#if defined(SEB_USE_WPE)
    return currentTitle_;
#else
    return QStringLiteral("SEB (WPE placeholder)");
#endif
}

bool WPEBrowserView::canGoBack() const
{
    return false;
}

bool WPEBrowserView::canGoForward() const
{
    return false;
}

void WPEBrowserView::load(const QUrl &url)
{
    currentUrl_ = url;
    emit urlChanged(url);

#if defined(SEB_USE_WPE)
    if (wpeRootObject_) {
        wpeRootObject_->setProperty("url", url);
    }
#else
    if (placeholder_) {
        placeholder_->setText(QStringLiteral("WPE backend not enabled in this build.\n\nRequested URL:\n%1").arg(url.toString()));
    }
#endif
}

void WPEBrowserView::back()
{
#if defined(SEB_USE_WPE)
    if (wpeRootObject_) {
        QMetaObject::invokeMethod(wpeRootObject_, "goBack", Qt::QueuedConnection);
    }
#endif
}

void WPEBrowserView::forward()
{
#if defined(SEB_USE_WPE)
    if (wpeRootObject_) {
        QMetaObject::invokeMethod(wpeRootObject_, "goForward", Qt::QueuedConnection);
    }
#endif
}

void WPEBrowserView::reload()
{
#if defined(SEB_USE_WPE)
    if (wpeRootObject_) {
        QMetaObject::invokeMethod(wpeRootObject_, "reload", Qt::QueuedConnection);
    }
#endif
}

void WPEBrowserView::setNavigationPolicy(NavigationPolicy policy)
{
    navigationPolicy_ = std::move(policy);
}

void WPEBrowserView::setUploadsAllowed(bool allowed)
{
    uploadsAllowed_ = allowed;
    Q_UNUSED(uploadsAllowed_);
}

void WPEBrowserView::findText(const QString &text)
{
    Q_UNUSED(text);
}

void WPEBrowserView::openDevTools() {}

}  // namespace seb::browser::engine

