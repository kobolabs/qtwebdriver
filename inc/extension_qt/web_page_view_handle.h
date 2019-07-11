#pragma once

#include <string>

#include "widget_view_handle.h"

#include <QtCore/QPointer>

#include <QtCore/QtGlobal>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtWidgets/QWidget>
#include <QtWebKitWidgets/QWebPage>
#else
#include <QtGui/QWidget>
#include <QtWebKit/QtWebKit>
#endif

namespace webdriver {

class WebPageViewHandle : public QViewHandle {
public:
    WebPageViewHandle();
    WebPageViewHandle(QWidget* view, QWebPage* page);
    
    virtual bool equals(const ViewHandle* other) const;
    QWebPage* getWebPage() { return webPage_.data(); };
    
protected:
    QPointer<QWebPage> webPage_;
//private:
	virtual ~WebPageViewHandle() {};
};

}  // namespace webdriver

