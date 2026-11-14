# Task – Lab 3 & Lab 4

## Comprehensive Report Preparation

The report should document all the work and experiments carried out during **Lab 3** and **Lab 4**, explaining the implementation steps and the results obtained.

---

##  Lab Overview

### Lab 3 — Digital Sensor using Arduino

**Topic:** Working with **digital sensors** (sensors that output only **HIGH (1)** or **LOW (0)** signals).

**What was covered:**
- **What a digital sensor is:** A sensor that gives a digital output — either 5V (HIGH/1) or 0V (LOW/0).
- **IR Sensor (Infrared):** The most common example — used for obstacle detection, line-following robots, and security systems. It has a transmitter and receiver; when infrared light hits an object and bounces back, the receiver detects it and the op-amp converts the signal to 0V or 5V.
- **PIR Sensor (Passive Infrared):** Detects **human motion** via body heat. Has two potentiometers — one for **sensitivity** and one for **delay time**.
- **Other sensors mentioned:** Magnetic/reed sensor, tilt sensor, Hall sensor, rain sensor, flame sensor, optical encoder, laser sensor, sound sensor.
- **How to represent a digital sensor in Proteus:** Three ways —
  1. As a **switch** (open = 0, closed = 1)
  2. As an **IR sensor module**
  3. Using a **library**
- **Arduino code:** Used `#define`, `pinMode()`, `digitalRead()`, `digitalWrite()`, `Serial.begin()`, and `delay()`.
- **Optimization tips:** Use `bool` instead of `int` for sensor state (saves memory), and understand the difference between defining variables globally vs. locally.
- **Practical application:** Controlling a **relay** (via a transistor + diode) to switch a **220V lamp** or a **DC motor** using the sensor signal — showing how a small Arduino signal can control high-power devices.

---

### Lab 4 — Analog Sensor & PWM using Arduino

**Topic:** Working with **analog sensors** (sensors that output a **range of values**, not just 0 or 1) and **PWM signals**.

#### Part 1 — Analog Sensors
- **What an analog sensor is:** Outputs a voltage between **0V and 5V** (e.g., 1V, 2.3V, 4V...), not just HIGH/LOW.
- **ADC (Analog-to-Digital Converter):** Arduino has a **10-bit ADC**, converting 0–5V into values from **0 to 1023**. Analog pins are **A0–A5**.
- **Reading analog values:** Use `analogRead(A0)` — no need to set pinMode.
- **Converting values:** Use the `map()` function to convert the 0–1023 range into voltage, percentage, or temperature.
- **Sensors used:**
  - **TMP36** — temperature sensor. Datasheet: 10mV per °C, output range from −40°C to 125°C. Used `map()` to convert sensor reading to temperature.
  - **LDR** — light sensor (light-dependent resistor). No fixed equation — monitored the voltage range and used `map()` to convert to 0–5V, then categorized light levels (Dark, Dark Light, Medium, High Light, Very High Light) using `if/else` statements.

#### Part 2 — PWM (Pulse Width Modulation)
- **What PWM is:** A **square wave signal** where you control the **duty cycle** (ratio of ON time to total period).
- **Duty cycle:** e.g., 60% duty cycle = signal is ON 60% of the time.
- **Uses:** Control **LED brightness**, **motor speed**, **sound tones** — simulating analog output using digital pins.
- **PWM pins on Arduino Uno/Nano:** **3, 5, 6, 9, 10, 11**
- **Resolution:** **8-bit (0–255)** — `analogWrite(pin, value)` where 0 = 0% and 255 = 100%.
- **Practical example:** Used the **TMP36 temperature sensor** to control **LED brightness** via PWM — mapped temperature range (−40 to 125) to PWM range (0–255), so the LED gets brighter as temperature rises. Verified with the **oscilloscope** in Proteus that the duty cycle changes with temperature.

---

## Requirements

At the end of the report, you must attach a **Google Drive link** containing all project files, including:

- **Proteus files** — simulation files (`.pdsprj`, etc.)
- **Hex files** — compiled `.hex` files for the microcontroller
- **Arduino files** — the `.ino` source code

---

## Important Notes

- Make sure all files are uploaded and organized inside a **clear folder** on Google Drive.
- Ensure the link is **accessible for download and viewing** (set sharing to *"Anyone with the link can view"*).
- The report must clearly explain the **implementation steps** and **results** for each lab.

---

## Summary Table

| Lab | Focus | Key Components |
|-----|-------|----------------|
| **Lab 3** | **Digital** sensors (0 or 1) | IR sensor, PIR sensor, relay, 220V lamp control |
| **Lab 4** | **Analog** sensors (0–5V) + **PWM** | TMP36, LDR, `analogRead()`, `map()`, `analogWrite()`, LED brightness control |

> **Note:** Both labs used **Proteus** for simulation and **Arduino** for programming. The homework requires a report + a Google Drive link containing Proteus files, Hex files, and Arduino code.
