#pragma once

class WebDriverInterface
{
public:
	virtual int configure(int argc, char** argv) = 0;
	virtual int start() = 0;
	virtual int stop(bool force) = 0;
};

Q_DECLARE_INTERFACE(WebDriverInterface, "com.kobo.nickel.WebDriverInterface")
