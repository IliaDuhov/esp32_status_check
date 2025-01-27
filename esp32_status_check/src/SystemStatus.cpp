#include "SystemStatus.h"

SystemStatus SystemStatus::getCurrentStatus() {
    SystemStatus status;
    status.uptime = millis() / 1000;
    status.heap = ESP.getFreeHeap();
    status.voltage = 3.3;
    return status;
}
