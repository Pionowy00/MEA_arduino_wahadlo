# 🔢 Arduino LCD Calculator

A simple **Arduino-based calculator** built using a 4×4 matrix keypad and a 16×2 LCD display. It performs basic arithmetic operations using integer calculations.

---

## 📸 Overview

The calculator allows users to enter two numbers, select an arithmetic operation, and display the result directly on the LCD.

## ⚙️ Features

- ➕ Addition
- ➖ Subtraction
- ✖️ Multiplication
- ➗ Integer division
- 🛡️ Division-by-zero protection
- 🧹 Clear/reset functionality
- 🔢 Right-aligned number input on the LCD
- 📟 Automatic display clearing when entering the second number

## 🧰 Components & Libraries

### Hardware
- Arduino board
- 16×2 LCD display
- 4×4 matrix keypad

### Libraries
- `Adafruit_LiquidCrystal`
- `Keypad`

## 🔌 Pin Configuration

### Keypad

| Connection | Arduino Pin |
|:---|:---:|
| Row 1 | 13 |
| Row 2 | 12 |
| Row 3 | 11 |
| Row 4 | 10 |
| Column 1 | 6 |
| Column 2 | 7 |
| Column 3 | 8 |
| Column 4 | 9 |

### LCD
The LCD is initialized using the Adafruit I2C backpack at address `0`.

## 🎮 Controls

| Key | Function |
|:---:|:---|
| `0–9` | Enter numbers |
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `#` | Calculate result |
| `C` | Clear calculator |

## 🧮 How It Works

1. Enter the first number using the keypad.
2. Select an arithmetic operation.
3. Enter the second number.
4. Press `#` to calculate.
5. The result appears on the LCD.

### Example

```text
First number: 125
Operation:    +
Second number: 25

Result:       150
```

## 🛡️ Error Handling

The calculator checks for division by zero before performing division.

If the second number is `0` and the selected operation is `/`, the LCD displays:

```text
DIVISION BY ZERO
NOT ALLOWED
```

This prevents the program from attempting an invalid division.

## 📌 Limitations

- Only two numbers can be used per calculation.
- Only one arithmetic operation is supported at a time.
- Calculations use the `int` data type.
- Division discards the fractional part (e.g. `7 / 2 = 3`).
- Decimal number input is not supported.

---

## 👨‍💻 Author

**Arduino LCD Calculator Project**

Built with Arduino, C++ and a bit of logic. ⚡