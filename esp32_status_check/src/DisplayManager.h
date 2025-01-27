#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SystemStatus.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

namespace DisplayManager {
    extern Adafruit_SSD1306 display;

    void init();
    void showStartupScreen();
    void updateStatusScreen(const SystemStatus& status);
    void updateMemoryGraphScreen(const SystemStatus& status);
}

#endif
