\# 🚦 Arduino Smart Crossroad



A simple Arduino-based crossroad traffic light controller that detects cars, manages lane priorities using a \*\*FIFO queue\*\*, and automatically switches traffic lights based on sensor activity.



The goal of this project is to simulate a basic smart intersection where each lane gets its turn without allowing multiple lanes to have a green light simultaneously.



<p align="center">

&#x20; <img src="https://img.shields.io/badge/Platform-Arduino-00979D?style=for-the-badge\&logo=arduino\&logoColor=white" alt="Arduino" />

&#x20; <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge\&logo=cplusplus\&logoColor=white" alt="C++" />

&#x20; <img src="https://img.shields.io/badge/Queue-FIFO-2E8B57?style=for-the-badge" alt="FIFO Queue" />

&#x20; <img src="https://img.shields.io/badge/Status-In%20Development-orange?style=for-the-badge" alt="In Development" />

</p>



\---



\## 📋 Table of Contents



\- \[✨ Features](#-features)

\- \[🚦 How It Works](#-how-it-works)

\- \[🔄 FIFO Queue](#-fifo-queue)

\- \[🔌 Hardware Requirements](#-hardware-requirements)

\- \[📍 Pin Configuration](#-pin-configuration)

\- \[⚙️ Installation](#️-installation)

\- \[🧠 Technical Overview](#-technical-overview)

\- \[🛠️ Future Improvements](#️-future-improvements)

\- \[📄 License](#-license)



\---



\## ✨ Features



\- 🚗 \*\*Car detection\*\* — sensors monitor four incoming lanes.

\- 🟢 \*\*Dynamic green light\*\* — the selected lane receives permission to move.

\- 🔴 \*\*Safe light switching\*\* — all inactive lanes remain red.

\- ⏱️ \*\*Five-second grace period\*\* — a lane stays green until no detection has occurred for five seconds.

\- 📥 \*\*FIFO queue management\*\* — waiting lanes are served in arrival order.

\- 🔁 \*\*Circular queue\*\* — an array-based queue efficiently manages waiting lanes.

\- ⚡ \*\*Non-blocking operation\*\* — `millis()` allows the controller to monitor sensors without using `delay()`.



\## 🚦 How It Works



The controller follows a simple sequence:



1\. All lanes start with red lights.

2\. A sensor detects a car in a lane.

3\. If no other lane is active, the detected lane can receive a green light.

4\. If another lane already has green, the newly detected lane joins the waiting queue.

5\. The active lane stays green while its sensor continues detecting a car.

6\. After five seconds without detection, the active lane returns to red.

7\. The next lane in the FIFO queue receives green.



\### Traffic light states



| Lane state | Red light | Green light |

|:---|:---:|:---:|

| Inactive lane | 🔴 ON | OFF |

| Active lane | OFF | 🟢 ON |

| No active lane | 🔴 ON | OFF |



\*\*Safety rule:\*\* At most one lane may have a green light at any given time.



\## 🔄 FIFO Queue



FIFO stands for \*\*First In, First Out\*\*. The first lane added to the queue is the first one served.



For example, imagine the top lane is currently green:



```text

&#x20;TOP LANE: GREEN

&#x20;      |

&#x20;      v

&#x20; Cars arrive:

&#x20; 1. RIGHT lane

&#x20; 2. BOTTOM lane

&#x20; 3. LEFT lane



&#x20; Waiting queue:

&#x20; FRONT                  BACK

&#x20; \[ RIGHT ] -> \[ BOTTOM ] -> \[ LEFT ]



&#x20; When TOP turns red:

&#x20; RIGHT becomes GREEN



&#x20; When RIGHT turns red:

&#x20; BOTTOM becomes GREEN



&#x20; When BOTTOM turns red:

&#x20; LEFT becomes GREEN

```



The queue uses a \*\*circular array\*\*, with three important variables:



| Variable | Purpose |

|:---|:---|

| `queue\[]` | Stores the waiting lane IDs. |

| `queueStart` | Points to the next lane to be served. |

| `queueEnd` | Points to the next available position for a new lane. |

| `queueSize` | Tracks the number of waiting lanes. |

| `queued\[]` | Prevents the same lane from being added multiple times. |



The queue can hold up to four distinct waiting lanes. Each lane can appear only once in the queue.



\## 🔌 Hardware Requirements



\- Arduino-compatible development board

\- 4 digital sensors for detecting cars

\- 4 red LEDs

\- 4 green LEDs

\- 8 current-limiting resistors for the LEDs

\- Breadboard and jumper wires

\- USB cable for programming and power



Additional components may be required depending on the sensors and the physical intersection design.



\## 📍 Pin Configuration



\### Sensors



| Lane | Arduino pin |

|:---|:---:|

| Top | `1` |

| Right | `2` |

| Bottom | `3` |

| Left | `4` |



\### Green LEDs



| Lane | Arduino pin |

|:---|:---:|

| Top | `5` |

| Right | `6` |

| Bottom | `7` |

| Left | `8` |



\### Red LEDs



| Lane | Arduino pin |

|:---|:---:|

| Top | `9` |

| Right | `10` |

| Bottom | `11` |

| Left | `12` |



> \*\*Note:\*\* On many Arduino boards, pins 0 and 1 are used for serial communication. If you are using an Arduino Uno or a similar board, consider moving the top sensor from pin 1 to another available digital pin.



\## ⚙️ Installation



1\. Clone this repository:



&#x20;  ```bash

&#x20;  git clone https://github.com/YOUR-USERNAME/arduino-smart-crossroad.git

&#x20;  ```



2\. Open the project in the Arduino IDE.



3\. Connect the sensors and LEDs according to the pin configuration.



4\. Select the correct board and serial port.



5\. Upload the sketch to your Arduino.



6\. Test each sensor and verify that the traffic lights switch correctly.



\### Sensor assumptions



The current implementation assumes that a sensor outputs `HIGH` when it detects a car and `LOW` otherwise.



The controller uses `millis()` to track the five-second grace period without blocking sensor monitoring.



\*\*Important:\*\* A presence sensor may remain `HIGH` while a car is stationary. In that case, the timer will continue resetting. For a real installation, distinguish vehicle presence from vehicle movement and add appropriate safety controls.



\## 🧠 Technical Overview



This project demonstrates several fundamental programming concepts:



\- \*\*Arrays\*\* — storing sensor and LED pin assignments.

\- \*\*Functions\*\* — separating traffic light control and queue operations.

\- \*\*State management\*\* — tracking the currently active lane.

\- \*\*FIFO data structures\*\* — preserving the order in which lanes join the queue.

\- \*\*Circular buffers\*\* — reusing array positions efficiently.

\- \*\*Boolean flags\*\* — preventing duplicate queue entries.

\- \*\*Time-based logic\*\* — using `millis()` instead of blocking delays.



The project is designed as a learning exercise in embedded programming, basic automation, and data structures.



\## 🛠️ Future Improvements



Potential additions include:



\- \[ ] Use separate sensors to detect vehicle arrival and departure.

\- \[ ] Add a pedestrian crossing system.

\- \[ ] Introduce yellow lights and an all-red transition interval.

\- \[ ] Display the queue state through the Serial Monitor or an LCD.

\- \[ ] Add configurable green-light durations.

\- \[ ] Detect and handle faulty sensors.

\- \[ ] Add a physical intersection model.

\- \[ ] Implement a more advanced priority system for emergency vehicles.

\- \[ ] Add a simulation mode for testing different traffic scenarios.



\## 📄 License



This project is intended for educational and experimental purposes.



If you plan to publish it publicly, consider adding an \[MIT License](https://choosealicense.com/licenses/mit/) to make the terms of reuse clear.



\---



<p align="center">

&#x20; <b>🚦 One intersection. Four lanes. One green light at a time.</b>

&#x20; <br />

&#x20; <sub>Built with Arduino and a little bit of logic.</sub>

</p>

