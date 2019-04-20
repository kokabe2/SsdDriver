#include "SsdDriver.h"

#include <stddef.h>
#include <stdlib.h>
#include "LedDriver.h"
#include "LedDriverPrivate.h"
#include "RuntimeError.h"

enum {
  kNonsenseEncoding = 0,
};

struct SsdDriverStruct {
  LedDriverStruct base;
  uint8_t (*decoder)(uint8_t);
  uint8_t encoding;
};

static bool Validate(uint8_t* ioAddress, uint8_t (*decoder)(uint8_t)) {
  if (!ioAddress)
    RUNTINE_ERROR("SSD Driver: null I/O address", 0);
  else if (!decoder)
    RUNTINE_ERROR("SSD Driver: null decode function", 0);
  else
    return true;

  return false;
}

static uint8_t ConvertToBitFrom(int segmentNumber) {
  return 1 << (segmentNumber - 1);
}

static SsdDriver NewInstance(uint8_t* ioAddress, uint8_t (*decoder)(uint8_t)) {
  SsdDriver self = calloc(1, sizeof(struct SsdDriverStruct));
  if (!self) return NULL;

  self->base.ioAddress = ioAddress;
  self->base.decoder = ConvertToBitFrom;
  self->decoder = decoder;

  return self;
}

SsdDriver SsdDriver_Create(uint8_t* ioAddress, uint8_t (*decoder)(uint8_t)) {
  if (!Validate(ioAddress, decoder)) return NULL;

  SsdDriver self = NewInstance(ioAddress, decoder);
  if (self) LedDriver_TurnAllOff(&self->base);

  return self;
}

static void DeleteInstance(SsdDriver* self) {
  free(*self);
  *self = NULL;
}

void SsdDriver_Destroy(SsdDriver* self) {
  if (!self || !*self) return;

  LedDriver_TurnAllOff(&(*self)->base);
  DeleteInstance(self);
}

void SsdDriver_TurnOn(SsdDriver self, int segmentNumber) {
  LedDriver_TurnOn(&self->base, segmentNumber);
}

void SsdDriver_TurnOff(SsdDriver self, int segmentNumber) {
  LedDriver_TurnOff(&self->base, segmentNumber);
}

void SsdDriver_TurnAllOn(SsdDriver self) { LedDriver_TurnAllOn(&self->base); }

void SsdDriver_TurnAllOff(SsdDriver self) { LedDriver_TurnAllOff(&self->base); }

bool SsdDriver_IsOn(SsdDriver self, int segmentNumber) {
  return LedDriver_IsOn(&self->base, segmentNumber);
}

bool SsdDriver_IsOff(SsdDriver self, int segmentNumber) {
  return LedDriver_IsOff(&self->base, segmentNumber);
}

static bool IsInvalid(SsdDriver self) {
  if (self) return false;

  RUNTINE_ERROR("SSD Driver: null instance", 0);
  return true;
}

static void SetSsdImageBit(SsdDriver self, uint8_t encoding) {
  *self->base.ioAddress = self->decoder(encoding);
  self->encoding = encoding;
}

void SsdDriver_Set(SsdDriver self, uint8_t encoding) {
  if (IsInvalid(self)) return;

  SetSsdImageBit(self, encoding);
}

static uint8_t GetSsdEncoding(SsdDriver self) { return self->encoding; }

uint8_t SsdDriver_Get(SsdDriver self) {
  if (IsInvalid(self)) return kNonsenseEncoding;

  return GetSsdEncoding(self);
}
