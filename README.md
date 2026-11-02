# Arduino I2C LCD Marquee & Event Display

An interactive 16x2 LCD display project built in **Tinkercad** using an **I2C backpack** and the **Adafruit_LiquidCrystal** library. It showcases alternating event screens (`display1` and `display2`), text swapping, dynamic screen-shifting animations, and a custom timing function built with `millis()`.

---

## 🛠 Features
* **I2C Display Control:** Uses the `Adafruit_LiquidCrystal` library to drive a 16x2 character display over an I2C interface.
* **Custom Timing Function (`waitMillis`):** Replaces standard blocking `delay()` calls with a custom wrapper utilizing `millis()`.
* **Dynamic Animations:** Features alternating layouts, inverted line ordering, and smooth back-and-forth horizontal screen scrolling (`scrollDisplayRight` / `scrollDisplayLeft`).
* **Modular Code Structure:** Clean separation of concerns into distinct `setup()`, `display1()`, `display2()`, and `loop()` functions.

---

## 📦 Hardware Requirements
* **Arduino Uno** (or compatible microcontroller)
* **16x2 LCD Display** with an **I2C Backpack** (PCF8574 / MCP230xx expander)
* Connecting jumper wires

---

## 💻 Code Overview

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

// Custom timing function utilizing millis()
void waitMillis(unsigned long duration) {
  unsigned long startMillis = millis();
  while (millis() - startMillis < duration) {
    // Wait loop
  }
}

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1); // Turn backlight ON
}

void loop() {
  display1();
  display2();
}
