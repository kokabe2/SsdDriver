#pragma once

#include <stdint.h>

typedef struct LedDriverStruct {
  uint8_t* ioAddress;
  uint8_t (*decoder)(int);
} LedDriverStruct;
