# HC-SR04 Interfacing with ESP32 using FreeRTOS (Register-Level Programming)

## Overview

This project demonstrates interfacing the HC-SR04 ultrasonic distance sensor with the ESP32 using FreeRTOS and direct register-level GPIO programming instead of high-level ESP-IDF GPIO APIs.

The experiment focuses on:

- Register-level GPIO control
- ESP32 GPIO architecture
- FreeRTOS task management
- Ultrasonic distance measurement
- Precise microsecond timing
- Embedded systems programming concepts

---

# Hardware Used

- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires
- Voltage Divider (for Echo pin protection)

---

# Wiring

| HC-SR04 | ESP32 |
|----------|--------|
| VCC | 5V |
| GND | GND |
| TRIG | GPIO5 |
| ECHO | GPIO18 |

> ⚠️ **Important**
>
> The HC-SR04 Echo pin outputs **5V**.
> ESP32 GPIO pins are **NOT 5V tolerant**.
>
> Use a voltage divider or logic level shifter on the Echo pin.

---

# Features

- Direct GPIO register manipulation
- FreeRTOS task-based design
- Microsecond pulse generation
- Echo pulse timing measurement
- Distance calculation in centimeters
- ESP-IDF v5.x compatible

---
