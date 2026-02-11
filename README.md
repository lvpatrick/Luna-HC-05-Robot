Arduino Robot Car Control with HC-05/HC-06 Bluetooth

Control your Arduino robot car using HC-05 or HC-06 Bluetooth module via smartphone.

Wiring Diagram

L298N to Arduino Connection
| L298N | Arduino |
|-------|---------|
| ENA   | Pin 9   |
| ENB   | Pin 10  |
| IN1   | Pin 8   |
| IN2   | Pin 7   |
| IN3   | Pin 6   |
| IN4   | Pin 5   |
| GND   | GND     |

HC-05/HC-06 to Arduino Connection
| HC-05/HC-06 | Arduino |
|-------------|---------|
| TX          | Pin 0 (RX) |
| RX          | Pin 1 (TX) |
| VCC         | 5V         |
| GND         | GND        |

⚠️ CRITICAL NOTES - MUST READ!

 NOTE 1: Serial Communication Conflict During Code Upload

PROBLEM:
Arduino uses pins 0 (RX) and 1 (TX) for TWO purposes:
Communication with computer via USB (code uploading, Serial Monitor)
Communication with HC-05/HC-06 Bluetooth module

⚠️ These two cannot work simultaneously!

CORRECT PROCEDURE:

```
STEP 1: DISCONNECT all TX/RX wires from HC-05/HC-06 to Arduino pins 0,1
STEP 2: Plug USB cable and upload code normally
STEP 3: After successful upload, UNPLUG USB cable
STEP 4: RECONNECT HC-05/HC-06 TX/RX wires to pins 0,1
STEP 5: Power up Arduino (battery/USB/external power)
```

⚠️ DO NOT keep HC-05/HC-06 TX/RX connected while uploading code!

⚠️ REPEAT steps 1-4 EVERY TIME you upload new code!

NOTE 2: Serial Monitor Limitations

- When HC-05/HC-06 is connected to pins 0,1, you **CANNOT** use Serial Monitor on your computer
- The USB port and Bluetooth module share the same serial lines - they conflict!

🔧 DEBUGGING OPTIONS:
Option A - Temporary Debugging:
1. Disconnect HC-05/HC-06 TX/RX from pins 0,1
2. Use Serial Monitor normally
3. Reconnect Bluetooth module after debugging

Option B - Use SoftwareSerial (Recommended for debugging):
```cpp
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11, 12); // RX, TX on different pins

void setup() {
  Serial.begin(9600);     // For USB debugging
  bluetooth.begin(9600);  // For Bluetooth
}
```

NOTE 3: Voltage Compatibility

HC-05:
Operating voltage: 3.3V - 5V
RX pin ONLY accepts 3.3V!
Using 5V directly may damage the module
Solution: Use voltage divider or buy pre-configured module
HC-06:
Operating voltage: 3.3V - 5V
Can work directly with Arduino 5V pins
More forgiving than HC-05

🔧 Simple Voltage Divider for HC-05 RX:
```
Arduino TX (5V) ---[1KΩ]---●---[2KΩ]--- GND
                           |
                        HC-05 RX (3.3V)
```

NOTE 4: Power Supply

Arduino 5V pin can power HC-05/HC-06 (up to ~50mA)
For L298N motor driver, use **SEPARATE POWER SUPPLY** (battery pack)
DO NOT power motors through Arduino 5V pin!
Common ground: Connect Arduino GND, L298N GND, and battery GND together

Control Commands

| Key     | Function            | Description                    |
|---------|---------------------|--------------------------------|
| F / f   | Forward             | Move robot forward            |
| B / b   | Backward            | Move robot backward           |
| L / l   | Left                | Turn left                     |
| R / r   | Right               | Turn right                    |
| S / s   | Stop                | Stop all motors               |
| 0       | Speed 0             | Motors stopped (0)            |
| 1       | Speed 1 (Low)       | Speed: 80/255                 |
| 2       | Speed 2 (Medium)    | Speed: 150/255                |
| 3       | Speed 3 (High)      | Speed: 200/255                |
| 4       | Speed 4 (Maximum)   | Speed: 255/255                |

Recommended Apps

**Android:**
Arduino Bluetooth Controller
Bluetooth RC Car
Arduino Bluetooth RC Car

**iOS:**
Bluefruit (Adafruit)
LightBlue
HM10 Bluetooth

Custom App:
MIT App Inventor (Free, easy to create your own app)

Troubleshooting Guide

1. Car Doesn't Move
```
Check battery/power supply
Verify L298N connections
Are ENA/ENB pins enabled? (analogWrite value > 0)
Test motors directly with battery
Check motor driver voltage
```

2. Can't Connect Bluetooth
```
Verify TX→RX, RX→TX connections (cross connection!)
Check baud rate (try 9600 or 38400)
LED on HC-05/HC-06 should blink rapidly when not connected
LED becomes solid when connected
Try restarting Arduino and phone Bluetooth
```

3. Motors Run Wrong Direction
```
Swap motor wires on L298N output
Or change logic in code:
Move forward: IN1 HIGH, IN2 LOW
Move backward: IN1 LOW, IN2 HIGH
```

4. Upload Fails
```
MOST COMMON ISSUE!
Did you disconnect HC-05/HC-06 TX/RX from pins 0,1?
Is the correct board and port selected?
Try pressing Arduino reset button before uploading
```

5. Erratic Movement / Noise
```
Add decoupling capacitors (100µF) near motor driver
Ensure common ground between all components
Separate power for motors and logic
Check wheel mounting and friction
```

6. Bluetooth Works but No Motor Control
```
Check L298N ENA/ENB pins - they need PWM signal!
Verify analogWrite is being called
Test with simple blink sketch first
```

📁 Code Structure

```cpp
// Motor control pins
#define enA 9    // Speed control A
#define enB 10   // Speed control B
#define in1 8    // Direction control 1
#define in2 7    // Direction control 2
#define in3 6    // Direction control 3
#define in4 5    // Direction control 4

int motorSpeed = 150;  // Default speed (0-255)

void setup() {
  // Initialize motor pins
  // Set initial speed
  // Initialize Serial for Bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    // Process commands
  }
}
```

Quick Start Guide

First Time Setup:
1. Upload code WITHOUT connecting Bluetooth module
2. Disconnect USB
3. Connect HC-05/HC-06 to pins 0,1
4. Power up Arduino
5. Connect phone to Bluetooth module
6. Send commands via app

Every Code Update:
1. DISCONNECT Bluetooth TX/RX wires
2. Upload new code
3. Disconnect USB
4. Reconnect Bluetooth wires
5. Ready to use

License
MIT License - Free to use, modify, and distribute. Attribution appreciated but not required.

---

Support
If you find this guide helpful, please give it a star on GitHub!

Questions or Issues? Open an issue on GitHub or contact via email.

---

*Happy building! 🤖*
