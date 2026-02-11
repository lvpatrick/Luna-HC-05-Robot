
README.txt

Trang
1
/
1
100%
# HC-05 Bluetooth Controlled Robot

A simple Arduino-based robot car controlled via Bluetooth using the HC-05 module. The robot can move forward, backward, turn left, right, and stop via commands sent from a smartphone.

## Features

- Controlled via Bluetooth (HC-05)
- Basic movement: Forward, Backward, Left, Right, Stop
- Adjustable motor speed
- Compatible with most L298N motor driver modules

## Components

- Arduino Uno (or Nano)
- HC-05 Bluetooth Module
- L298N Motor Driver
- DC Motors with wheels
- Power Supply (Battery or Adapter)
- Jumper Wires
- Robot chassis

## Wiring Diagram

![Wiring Diagram](./assets/wiring-diagram.png)

## Arduino Pinout

| Component | Pin      |
|-----------|----------|
| ENA       | D9       |
| IN1       | D3       |
| IN2       | D4       |
| ENB       | D10      |
| IN3       | D5       |
| IN4       | D6       |
| HC-05 TX  | Arduino RX (D0) |
| HC-05 RX  | Arduino TX (D1) |

## Command List

| Command | Action   |
|---------|----------|
| F       | Forward  |
| B       | Backward |
| L       | Left     |
| R       | Right    |
| S       | Stop     |

## Code

See `robot_hc05.ino` in this repository.

## License

This project is licensed under the [MIT License](./LICENSE).
Đang hiển thị README.txt.
