#pragma once

#include "browser_view.h"

#include <QPointer>

QT_BEGIN_NAMESPACE
class QLabel;
class QWidget;
QT_END_NAMESPACE

namespace seb::browser::engine {

class WPEBrowserView final : public BrowserView
{
    Q_OBJECT

public:
    explicit WPEBrowserView(QWidget *parentWidget, QObject *parent = nullptr);
    ~WPEBrowserView() override;

    QWidget *widget() override;

    QUrl url() const override;
    QString title() const override;

    bool canGoBack() const override;
    bool canGoForward() const override;

    void load(const QUrl &url) override;
    void back() override;
    void forward() override;
    void reload() override;

    void setNavigationPolicy(NavigationPolicy policy) override;
    void setUploadsAllowed(bool allowed) override;
    void findText(const QString &text) override;
    void openDevTools() override;

private:
    NavigationPolicy navigationPolicy_;
    bool uploadsAllowed_ = true;

#if defined(SEB_USE_WPE)
    // Real WPE-backed members go here once WPE Qt headers/libs are enabled.
    // We keep this behind a build flag so the default QtWebEngine build still works.
    QPointer<QWidget> wpeWidget_;
    QUrl currentUrl_;
    QString currentTitle_;
#else
    QPointer<QLabel> placeholder_;
    QUrl currentUrl_;
#endif
};

}  // namespace seb::browser::engine

