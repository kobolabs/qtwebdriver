/****************************************************************************
**
** Copyright © 1992-2014 Cisco and/or its affiliates. All rights reserved.
** All rights reserved.
** 
** $CISCO_BEGIN_LICENSE:LGPL$
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** $CISCO_END_LICENSE$
**
****************************************************************************/

#include "extension_qt/web_page_view_handle.h"

namespace webdriver {

WebPageViewHandle::WebPageViewHandle() 
	: webPage_(NULL) { }
 
WebPageViewHandle::WebPageViewHandle(QWidget* view, QWebPage* webPage)
	: QViewHandle(view), webPage_(webPage) { }

bool WebPageViewHandle::equals(const ViewHandle* other) const {
	const WebPageViewHandle* toCompare = dynamic_cast<const WebPageViewHandle*>(other);
	if (NULL == toCompare) return false;

	return QViewHandle::equals(other) && (webPage_ == toCompare->webPage_);
}

} // namespace webdriver
