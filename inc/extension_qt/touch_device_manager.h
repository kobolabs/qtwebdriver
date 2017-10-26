#ifndef TOUCHDEVICEMANAGER
#define TOUCHDEVICEMANAGER

#include <QtCore/QDebug>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtWidgets/QWidget>
#include <QtGui/QTouchDevice>
#else
#include <QtGui/QWidget>
#endif
#include <QtGui/QTouchEvent>

#include "base/memory/singleton.h"

namespace webdriver {

class TouchDeviceManager {
public:
    void setTouchDevice(QTouchDevice* _device);
    QTouchDevice* getTouchDevice();

    static TouchDeviceManager* GetInstance();
private:
    TouchDeviceManager();
    ~TouchDeviceManager();
    friend struct DefaultSingletonTraits<TouchDeviceManager>;

    QTouchDevice* _device;

    DISALLOW_COPY_AND_ASSIGN(TouchDeviceManager);
};

}
#endif
