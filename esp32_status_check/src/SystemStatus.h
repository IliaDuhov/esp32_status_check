#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include <Arduino.h>

struct SystemStatus {
    unsigned long uptime;
    size_t heap;
    float voltage;

    static SystemStatus getCurrentStatus();
};

#endif
