#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct SsdDriverStruct* SsdDriver;

SsdDriver SsdDriver_Create(uint8_t* ioAddress, uint8_t (*decoder)(uint8_t));
void SsdDriver_Destroy(SsdDriver* self);
void SsdDriver_TurnOn(SsdDriver self, int segmentNumber);
void SsdDriver_TurnOff(SsdDriver self, int segmentNumber);
void SsdDriver_TurnAllOn(SsdDriver self);
void SsdDriver_TurnAllOff(SsdDriver self);
bool SsdDriver_IsOn(SsdDriver self, int segmentNumber);
bool SsdDriver_IsOff(SsdDriver self, int segmentNumber);
void SsdDriver_Set(SsdDriver self, uint8_t encoding);
uint8_t SsdDriver_Get(SsdDriver self);
