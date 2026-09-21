# Arduino Dual Traffic Light System

A simple C++ Arduino project simulating a two-way (Left Side / Right Side) traffic light intersection using basic digital outputs and custom timing loops.

---

## 📌 Pin Configuration

| Light Component | Side | Arduino Pin |
| :--- | :--- | :--- |
| **Green LED** | Left Side | Pin 11 |
| **Red LED** | Left Side | Pin 10 |
| **Green LED** | Right Side | Pin 5 |
| **Red LED** | Right Side | Pin 6 |

---

## 🚦 Traffic Cycle Breakdown

The system operates on a **12-second total cycle** using non-blocking time checks (`millis()`):

```
Time Interval    Left Light    Right Light   Phase Description
─────────────────────────────────────────────────────────────────────────────
0s - 4s          🟢 GREEN      🔴 RED        Left side traffic flows
4s - 6s          🔴 RED        🔴 RED        Safety transition break
6s - 10s         🔴 RED        🟢 GREEN      Right side traffic flows
10s - 12s        🔴 RED        🔴 RED        Safety transition break
```

### Timeline
- **Phase 1 (0 – 4s):** Left side Green, Right side Red.
- **Phase 2 (4 – 6s):** Left side Red, Right side Red *(All-Red clearance interval)*.
- **Phase 3 (6 – 10s):** Left side Red, Right side Green.
- **Phase 4 (10 – 12s):** Left side Red, Right side Red *(All-Red clearance interval)*.

---

## 🛠️ Circuit Setup

1. **LEDs:** Connect 4 LEDs (2 Green, 2 Red) with appropriate current-limiting resistors (e.g., 220Ω) to the specified digital pins.
2. **Ground:** Connect the cathode (short leg) of each LED to the Arduino `GND`.
3. **Power:** Upload the code to your Arduino board via USB.

---

## ⚙️ How to Use

1. Open the Arduino IDE.
2. Create a new sketch and paste the contents of `code.cpp`.
3. Select your Arduino board and port under **Tools**.
4. Click **Upload**.