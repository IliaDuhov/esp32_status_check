#include <Arduino.h>
#include "DisplayManager.h"
#include "SystemStatus.h"

unsigned long lastUpdate = 0;
bool showStatistics = true;

void setup() {
    Serial.begin(115200);
    DisplayManager::init();
    DisplayManager::showStartupScreen();
    delay(2000);
}

void loop() {
    unsigned long currentTime = millis();
    SystemStatus status = SystemStatus::getCurrentStatus();

    if (showStatistics && currentTime - lastUpdate >= 5000) {
        DisplayManager::updateMemoryGraphScreen(status);
        showStatistics = false;
        lastUpdate = currentTime;
    } else if (!showStatistics && currentTime - lastUpdate >= 20000) {
        DisplayManager::updateStatusScreen(status);
        showStatistics = true;
        lastUpdate = currentTime;
    }
}
