#include "wpe_browser_view.h"

#include <QLabel>
#include <QUrl>

namespace seb::browser::engine {

WPEBrowserView::WPEBrowserView(QWidget *parentWidget, QObject *parent)
    : BrowserView(parent)
{
#if defined(SEB_USE_WPE)
    Q_UNUSED(parentWidget);
    // When SEB_USE_WPE is enabled we will construct the real WPEView widget here.
    wpeWidget_ = new QWidget(parentWidget);
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
    return wpeWidget_;
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
    // TODO (WPE): call WPEView::load(url)
#else
    if (placeholder_) {
        placeholder_->setText(QStringLiteral("WPE backend not enabled in this build.\n\nRequested URL:\n%1").arg(url.toString()));
    }
#endif
}

void WPEBrowserView::back() {}
void WPEBrowserView::forward() {}
void WPEBrowserView::reload() {}

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

