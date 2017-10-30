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

#include <QtCore/QObject>
#include <QtCore/QTextCodec>

#include <QtConcurrent/QtConcurrentRun>
#include <QtWebKitWidgets/QWebView>

#include <iostream>

#include "webdriver_setup.h"

#include "base/at_exit.h"
#include "webdriver_server.h"
#include "webdriver_view_transitions.h"
#include "versioninfo.h"
#include "webdriver_route_table.h"
#include "commands/shutdown_command.h"
#include "webdriver_route_patterns.h"

#if defined(OS_WIN)
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#define HAVE_STRUCT_TIMESPEC 1
#endif

#include "extension_qt/web_view_creator.h"
#include "extension_qt/web_view_executor.h"
#include "extension_qt/web_view_enumerator.h"
#include "extension_qt/qwebviewext.h"
#include "extension_qt/graphics_web_view_executor.h"
#include "extension_qt/graphics_web_view_enumerator.h"

#include "extension_qt/q_view_runner.h"
#include "extension_qt/q_session_lifecycle_actions.h"
#include "extension_qt/widget_view_creator.h"
#include "extension_qt/widget_view_enumerator.h"
#include "extension_qt/widget_view_executor.h"
#include "extension_qt/wd_event_dispatcher.h"
#include "extension_qt/vnc_event_dispatcher.h"
#include "extension_qt/uinput_event_dispatcher.h"

#include "setup/plugin_session_lifecycle_actions.h"
#include "setup/session_notifier.h"

#include "extension_qt/uinput_manager.h"
#include "webdriver_switches.h"

WebDriverPlugin::WebDriverPlugin() : super()
{
}

int WebDriverPlugin::configure(int argc, char** argv)
{
    webdriver::ViewRunner::RegisterCustomRunner<webdriver::QViewRunner>();

    webdriver::SessionLifeCycleActions::RegisterCustomLifeCycleActions<webdriver::PluginSessionLifeCycleActions>();
    connect(webdriver::SessionNotifier::GetInstance(), &webdriver::SessionNotifier::sessionStarted, this, &WebDriverPlugin::sessionStarted);
    connect(webdriver::SessionNotifier::GetInstance(), &webdriver::SessionNotifier::sessionEnded, this, &WebDriverPlugin::sessionEnded);

    webdriver::ViewTransitionManager::SetURLTransitionAction(new webdriver::URLTransitionAction_CloseOldView());

    /* Configure widget views */
    webdriver::ViewCreator* widgetCreator = NULL;
    webdriver::ViewCreator* webCreator = NULL;
    webdriver::ViewCreator* qmlCreator =  NULL;

    webCreator = new webdriver::QWebViewCreator();
    webCreator->RegisterViewClass<QWebViewExt>("QWebViewExt");
    webdriver::ViewFactory::GetInstance()->AddViewCreator(webCreator);

    /* Configure WebView support */
    webdriver::ViewEnumerator::AddViewEnumeratorImpl(new webdriver::WebViewEnumeratorImpl());
    webdriver::ViewCmdExecutorFactory::GetInstance()->AddViewCmdExecutorCreator(new webdriver::QWebViewCmdExecutorCreator());

    /* Configure GraphicsWebView support */
    webdriver::ViewEnumerator::AddViewEnumeratorImpl(new webdriver::GraphicsWebViewEnumeratorImpl());
    webdriver::ViewCmdExecutorFactory::GetInstance()->AddViewCmdExecutorCreator(new webdriver::GraphicsWebViewCmdExecutorCreator());

    webdriver::ViewEnumerator::AddViewEnumeratorImpl(new webdriver::WidgetViewEnumeratorImpl());
    webdriver::ViewCmdExecutorFactory::GetInstance()->AddViewCmdExecutorCreator(new webdriver::QWidgetViewCmdExecutorCreator());
    
    CommandLine cmd_line(CommandLine::NO_PROGRAM);
#if defined(OS_WIN)
    for (int var = 0; var < argc; ++var) {
        cmd_line.AppendSwitch(argv[var]);
    }
#elif defined(OS_POSIX)
    cmd_line.InitFromArgv(argc, argv);
#endif

#if defined(OS_WIN)
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    system("qtenv2.bat vsvars");
#else  //QT_VERSION
    system("qtvars.bat vsvars");
#endif //QT_VERSION
#endif //OS_WIN

    /* check for Linux UInput input support */
#ifdef OS_LINUX
    if (cmd_line.HasSwitch(webdriver::Switches::kUserInputDevice))
    {
        UInputManager *manager = UInputManager::getInstance();
        if (!manager->isReady())
        {
            manager->registerUinputDevice();
        }

        WDEventDispatcher::getInstance()->add(new UInputEventDispatcher(manager));
    }
#endif // OS_LINUX

    webdriver::Server* wd_server = webdriver::Server::GetInstance();
    return wd_server->Configure(cmd_line);
}

int WebDriverPlugin::start()
{
    webdriver::Server* wd_server = webdriver::Server::GetInstance();
    return wd_server->Start();
}

int WebDriverPlugin::stop(bool force)
{
    webdriver::Server* wd_server = webdriver::Server::GetInstance();
    return wd_server->Stop(force);
}

QObject* WebDriverPlugin::getObject()
{
    return this;
}