#ifndef PLUGIN_SESSION_LIFECYCLE_ACTIONS
#define PLUGIN_SESSION_LIFECYCLE_ACTIONS

#include "webdriver_session.h"

namespace webdriver {

class PluginSessionLifeCycleActions : public SessionLifeCycleActions {
public:
    PluginSessionLifeCycleActions(Session* session);
    virtual ~PluginSessionLifeCycleActions() {};

    virtual Error* PostInit(const base::DictionaryValue* desired_capabilities_dict,
                const base::DictionaryValue* required_capabilities_dict);

    virtual void BeforeTerminate(void);

private:

    DISALLOW_COPY_AND_ASSIGN(PluginSessionLifeCycleActions);
};

}  // namespace webdriver

#endif  // PLUGIN_SESSION_LIFECYCLE_ACTIONS
