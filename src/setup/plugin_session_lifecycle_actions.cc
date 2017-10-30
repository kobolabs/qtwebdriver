#include "setup/plugin_session_lifecycle_actions.h"
#include "setup/session_notifier.h"

namespace webdriver {

PluginSessionLifeCycleActions::PluginSessionLifeCycleActions(Session* session)
	: SessionLifeCycleActions(session) {}

Error* PluginSessionLifeCycleActions::PostInit(const base::DictionaryValue*, const base::DictionaryValue*) {
	SessionNotifier::GetInstance()->sessionStarted();
	return NULL;
}

void PluginSessionLifeCycleActions::BeforeTerminate(void) {
	SessionNotifier::GetInstance()->sessionEnded();
}

}
