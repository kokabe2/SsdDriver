# SsdDriver

[![Build Status](https://travis-ci.org/kokabe2/SsdDriver.svg?branch=master)](https://travis-ci.org/kokabe2/SsdDriver)

A seven-segment display driver for embedded systems.

## Features

- Multiple-instance module
- Written in C
- Testability
- MIT license

## Assumptions and constraints

- The implementation is memory-mapped I/O
- The I/O address is writable and readable
- The bit value 1 is segment on and 0 is segment off
- With decimal point
- Dynamic memory allocation is used
- Segment number 1 is LSB and 8 is MSB

## Usage

I recommend just copying SsdDriver.h and SsdDriver.c into your project.
Then just #include "SsdDriver.h" to use the SsdDriver functions.

## Function Documentation

### SsdDriver_Create

```C
SsdDriver SsdDriver_Create(uint8_t* ioAddress, uint8_t (*decoder)(uint8_t));
```

Create a SsdDriver instance.

Note: All segments will be off if successfully.

Inputs:

- `ioAddress` - The I/O address for seven-segment display.
- `decoder` - The function to convert to bit from the encoding.

Returns the instance if created successfully, NULL if an error occurred.

### SsdDriver_Destroy

```C
void SsdDriver_Destroy(SsdDriver* self);
```

Destroy a SsdDriver instance.

Note: All segments will be off if successfully.

Inputs:

- `self` - The pointer to SsdDriver instance.

### SsdDriver_TurnOn

```C
void SsdDriver_TurnOn(SsdDriver self, int segmentNumber);
```

Turn on a segment.

Inputs:

- `self` - The SsdDriver instance.
- `segmentNumber` - The number of segment to turn on.

### SsdDriver_TurnOff

```C
void SsdDriver_TurnOff(SsdDriver self, int segmentNumber);
```

Turn off a segment.

Inputs:

- `self` - The SsdDriver instance.
- `segmentNumber` - The number of segment to turn off.

### SsdDriver_TurnAllOn

```C
void SsdDriver_TurnAllOn(SsdDriver self);
```

Turn on all segments.

Inputs:

- `self` - The SsdDriver instance.

### SsdDriver_TurnAllOff

```C
void SsdDriver_TurnAllOff(SsdDriver self);
```

Turn off all segments.

Inputs:

- `self` - The SsdDriver instance.

### SsdDriver_IsOn

```C
bool SsdDriver_IsOn(SsdDriver self, int segmentNumber);
```

Check if the segment is on.

Inputs:

- `self` - The SsdDriver instance.
- `segmentNumber` - The number of segment to check.

### SsdDriver_IsOff

```C
bool SsdDriver_IsOff(SsdDriver self, int segmentNumber);
```

Check if the segment is off.

Inputs:

- `self` - The SsdDriver instance.
- `segmentNumber` - The number of segment to check.

### SsdDriver_Set

```C
void SsdDriver_Set(SsdDriver self, uint8_t encoding);
```

Turn on segments to display the encoding.

Inputs:

- `self` - The SsdDriver instance.
- `encoding` - The encoding to display.

### SsdDriver_Get

```C
uint8_t SsdDriver_Get(SsdDriver self);
```

Get the last set encoding.

Inputs:

- `self` - The SsdDriver instance.

## How to use this project

### Build

```bash
$ cd SsdDriver
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Run the tests

Either using `ctest` or `bin/gtests` in the build directory.
