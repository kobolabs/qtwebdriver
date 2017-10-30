#include "setup/session_notifier.h"

namespace webdriver {

SessionNotifier::SessionNotifier() {
}

SessionNotifier* SessionNotifier::GetInstance()
{
    return Singleton<SessionNotifier>::get();
}

}
