#include "extension_qt/touch_device_manager.h"

namespace webdriver {

TouchDeviceManager::TouchDeviceManager()
    : _device(new QTouchDevice) {
    _device->setType(QTouchDevice::TouchScreen);
}

TouchDeviceManager::~TouchDeviceManager() {
    delete _device;
}

QTouchDevice* TouchDeviceManager::getTouchDevice() {
    return _device;
}

TouchDeviceManager* TouchDeviceManager::GetInstance()
{
    return Singleton<TouchDeviceManager>::get();
}

}
