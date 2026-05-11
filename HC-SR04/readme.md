HC-SR04 Interfacing with ESP32 using FreeRTOS (Register-Level Programming)
Overview

This project demonstrates interfacing the HC-SR04 ultrasonic distance sensor with the ESP32 using FreeRTOS and direct register-level GPIO programming instead of high-level ESP-IDF GPIO APIs.

The experiment focuses on:

Register-level GPIO control
ESP32 GPIO architecture
FreeRTOS task management
Ultrasonic distance measurement
Precise microsecond timing
Embedded systems programming concepts
Hardware Used
ESP32 Development Board
HC-SR04 Ultrasonic Sensor
Breadboard
Jumper Wires
Voltage Divider (for Echo pin protection)
Wiring
HC-SR04	ESP32
VCC	5V
GND	GND
TRIG	GPIO5
ECHO	GPIO18

Important:
The HC-SR04 Echo pin outputs 5V.
ESP32 GPIO pins are 3.3V tolerant only.
Use a voltage divider or logic level shifter on the Echo pin.

Features
Direct GPIO register manipulation
FreeRTOS task-based design
Microsecond pulse generation
Echo pulse timing measurement
Distance calculation in centimeters
ESP-IDF v5.x compatible
Register-Level Concepts Used
GPIO Output Set
GPIO.out_w1ts
GPIO Output Clear
GPIO.out_w1tc
GPIO Input Read
GPIO.in
GPIO Direction Control
GPIO.enable_w1ts
GPIO.enable_w1tc
Distance Formula

Distance is calculated using:

distance = (time × speed_of_sound) / 2

Where:

Speed of sound = 0.0343 cm/µs
Division by 2 accounts for the round trip of the ultrasonic wave

Example Output
Distance: 12.45 cm
Distance: 12.39 cm
Distance: 12.51 cm
Learning Outcomes

This project helps in understanding:

ESP32 hardware registers
Memory-mapped I/O
FreeRTOS scheduling
Real-time embedded programming
Sensor interfacing
Low-level peripheral control
Future Improvements
GPIO interrupt-based echo detection
RMT peripheral implementation
Timer Group capture mode
Multi-sensor support
Non-blocking driver architecture
C++ class-based driver
ISR-safe event handling
License

This project is for learning and experimentation purposes.
