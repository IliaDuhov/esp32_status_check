#include "DisplayManager.h"

Adafruit_SSD1306 DisplayManager::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void DisplayManager::init() {
    if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
}

void DisplayManager::showStartupScreen() {
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("System Tracker"));
    display.display();
}

void DisplayManager::updateStatusScreen(const SystemStatus& status) {
    display.clearDisplay();

    display.setCursor(0, 0);
    display.print(F("Uptime: "));
    display.print(status.uptime);
    display.println(F(" s"));

    display.setCursor(0, 10);
    display.print(F("Heap: "));
    display.print(status.heap);
    display.println(F(" bytes"));

    display.setCursor(0, 20);
    display.print(F("Voltage: "));
    display.print(status.voltage);
    display.println(F(" V"));

    display.display();
}

void DisplayManager::updateMemoryGraphScreen(const SystemStatus& status) {
    display.clearDisplay();

    display.setCursor(0, 0);
    display.println(F("Memory Usage:"));

    const int totalHeap = 346500;
    int freeHeap = status.heap;
    int usedHeap = totalHeap - freeHeap + 45000;

    if (usedHeap < 1000) {
        usedHeap = 1000;
    }

    int usedBarWidth = map(usedHeap, 0, totalHeap, 1, 120);
    int freeBarWidth = 120 - usedBarWidth;

    int yGraph = 20;
    display.fillRect(0, yGraph, usedBarWidth, 10, SSD1306_WHITE);
    display.fillRect(usedBarWidth, yGraph, freeBarWidth, 10, SSD1306_BLACK);

    display.drawRect(0, yGraph, 120, 10, SSD1306_WHITE);

    display.setCursor(0, 35);
    display.print(F("Used: "));
    display.print(usedHeap);
    display.print(F(" bytes"));

    display.setCursor(0, 45);
    display.print(F("Free: "));
    display.print(freeHeap);
    display.print(F(" bytes"));

    display.display();
}
