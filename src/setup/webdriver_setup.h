#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "setup/WebDriverInterface.h"

class WebDriverPlugin : public QObject, public WebDriverInterface {
	Q_OBJECT
	Q_INTERFACES(WebDriverInterface)
	Q_PLUGIN_METADATA(IID "com.kobo.nickel.WebDriverPlugin")

public:
	WebDriverPlugin();
	int configure(int argc, char** argv);
	int start();
	int stop(bool force);
	QObject* getObject();

signals:
	void sessionStarted();
	void sessionEnded();

private:
	typedef QObject super;
};
