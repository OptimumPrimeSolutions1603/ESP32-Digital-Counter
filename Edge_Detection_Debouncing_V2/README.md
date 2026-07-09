# ESP32 Digital Counter - Version 2

Version 2 enhances the basic digital counter by implementing **edge detection** and **software debouncing**, ensuring the counter increments only once for each button press.

Unlike Version 1, holding the button no longer continuously increases the counter. The project now detects the transition from **HIGH** to **LOW**, making the button press more reliable and closer to real-world embedded system behavior.

---

## Features

- Increment counter using a push button
- One count per button press
- Software edge detection
- Basic software debouncing
- Display counter value on the Serial Monitor
- Uses ESP32's internal pull-up resistor (`INPUT_PULLUP`)

---

## Components Required

- ESP32 Development Board
- Push Button (4-pin tactile switch)
- Breadboard
- Jumper Wires

---

## Circuit Connections

| Component | ESP32 Pin |
|----------|-----------|
| Push Button | GPIO 4 |
| Push Button | GND |

> **Note:** The button is configured using the ESP32's internal pull-up resistor, so no external resistor is required.

---

## Working Principle

- The push button is connected between **GPIO 4** and **GND**.
- GPIO 4 is configured using `INPUT_PULLUP`, so it normally reads **HIGH**.
- Pressing the button connects the pin to **GND**, causing it to read **LOW**.
- The program compares the current button state with the previous button state.
- The counter increments only when the button transitions from **HIGH** to **LOW** (a new button press).
- A short debounce delay helps filter out unwanted switch bounce.

---

## Example Output

```
Counter = 1
Counter = 2
Counter = 3
Counter = 4
```

Holding the button does **not** continuously increment the counter.

---

## Concepts Learned

- Digital Inputs
- GPIO Configuration
- Internal Pull-Up Resistors
- Edge Detection
- Software Debouncing
- State Tracking
- Boolean Variables
- Conditional Statements (`if`)
- Logical AND (`&&`)
- Serial Communication

---

## Improvements Over Version 1

- Detects a button press only once
- Prevents continuous counting while the button is held
- Introduces state-based programming using previous and current button states
- Improves reliability by reducing the effects of switch bounce

---

## Future Improvements

- Multiple Buttons (Increment, Decrement & Reset)
- OLED Display Integration
- Long Press Detection
- Non-blocking Debouncing using `millis()`
- Improved User Interface

---

## Images

### Circuit Diagram

![Circuit Diagram](Images/circuit.jpeg)

### Demo

![Demo](Images/Demo.gif)

## Author

**Danger Volt**

Learning Embedded Systems one project at a time.