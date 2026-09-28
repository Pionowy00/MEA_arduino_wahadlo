\# Arduino 4-Sided Traffic Light



A simple Arduino project that controls four pairs of red and green LEDs arranged around four sides: \*\*top, right, bottom, and left\*\*.



Each side gets a green light for 5 seconds, followed by a 2-second period where all lights are red. The cycle then continues to the next side.



\## How It Works



The program uses two main functions:



\* `red()` — turns all red LEDs on and all green LEDs off.

\* `green(side\_green, side\_red)` — first sets all lights to red, then switches the selected side to green.



The `loop()` function cycles through the four sides:



```text

&#x20;       TOP

&#x20;        ↓

&#x20;    5s GREEN

&#x20;        ↓

&#x20;     2s RED

&#x20;        ↓

&#x20;      RIGHT

&#x20;        ↓

&#x20;    5s GREEN

&#x20;        ↓

&#x20;     2s RED

&#x20;        ↓

&#x20;     BOTTOM

&#x20;        ↓

&#x20;    5s GREEN

&#x20;        ↓

&#x20;     2s RED

&#x20;        ↓

&#x20;      LEFT

&#x20;        ↓

&#x20;    5s GREEN

&#x20;        ↓

&#x20;     2s RED

&#x20;        ↓

&#x20;     repeat

```



\## Pin Configuration



| Direction | Green LED | Red LED |

| --------- | --------- | ------- |

| Right     | Pin 2     | Pin 3   |

| Left      | Pin 7     | Pin 6   |

| Top       | Pin 9     | Pin 8   |

| Bottom    | Pin 5     | Pin 4   |



The pin assignments are defined at the beginning of the program:



```cpp

\#define GREEN\_RIGHT 2

\#define GREEN\_LEFT 7

\#define GREEN\_TOP 9

\#define GREEN\_BOTTOM 5



\#define RED\_RIGHT 3

\#define RED\_LEFT 6

\#define RED\_TOP 8

\#define RED\_BOTTOM 4

```



\## Timing



Each direction follows this sequence:



\* 🟢 Green — \*\*5 seconds\*\*

\* 🔴 All red — \*\*2 seconds\*\*



The total cycle takes:



```text

4 × (5 + 2) = 28 seconds

```



\## Why `changed` Is Used



The program uses a boolean variable:



```cpp

bool changed = false;

```



Without it, `green()` would be called continuously during the 5-second period.



Instead, this:



```cpp

if(!changed)

{

&#x20;   green(GREEN\_TOP, RED\_TOP);

&#x20;   changed = true;

}

```



ensures that `green()` is executed only \*\*once\*\* when the phase starts.



This is important because `green()` calls `red()` first:



```cpp

void green(int side\_green, int side\_red)

{

&#x20;   red();

&#x20;   digitalWrite(side\_green, HIGH);

&#x20;   digitalWrite(side\_red, LOW);

}

```



Calling it repeatedly could interfere with LED fade/transition behavior by repeatedly resetting the LEDs.



\## Requirements



\* Arduino board

\* 8 LEDs:



&#x20; \* 4 × red

&#x20; \* 4 × green

\* 8 appropriate current-limiting resistors

\* Breadboard

\* Jumper wires



\## Uploading



1\. Connect the LEDs according to the pin configuration.

2\. Open the project in the Arduino IDE.

3\. Select the correct Arduino board and port.

4\. Upload the program.

5\. The four-sided light sequence will start automatically.



\## Possible Improvements



Some possible extensions for the project:



\* Add smooth green/red fading using PWM.

\* Replace the repeated `while(millis() < ...)` sections with a state machine.

\* Use `millis()` without blocking the rest of the program.

\* Add yellow LEDs and a yellow transition phase.

\* Add buttons to manually change the active direction.

\* Add a pedestrian crossing mode.

\* Make the green-light duration configurable.



\## License



This project is intended for learning and experimentation with Arduino and basic embedded programming.



