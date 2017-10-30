#ifndef SESSION_NOTIFIER
#define SESSION_NOTIFIER

#include <QtCore/QObject>

#include "base/memory/singleton.h"

namespace webdriver {

class SessionNotifier : public QObject {
	Q_OBJECT

public:
    static SessionNotifier* GetInstance();

signals:
	void sessionStarted();
	void sessionEnded();

private:
    SessionNotifier();
    friend struct DefaultSingletonTraits<SessionNotifier>;

    DISALLOW_COPY_AND_ASSIGN(SessionNotifier);
};

}  // namespace webdriver

#endif  // SESSION_NOTIFIER
