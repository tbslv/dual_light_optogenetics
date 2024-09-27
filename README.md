# dual_light_optogenetics
split TTL signal to trigger 2 Thorlabs LEDs for Optogentics with varibale stimulation paramters



# Setup

Pin Definitions for Arduino Uno:
- Input Pin (TTL Signal): Connect the TTL signal to digital pin 2.
- Output Line 1: Connect the first output to digital pin 3.
- Output Line 2: Connect the second output to digital pin 4.

Power Connections:
VCC (Power Supply):
If your TTL signal and external components (like sensors or other hardware) require a 5V supply, you can use the Arduino's 5V pin. This pin provides 5V power from the USB or external power supply connected to the Arduino.
Alternatively, if you're using a different voltage (like 3.3V for some components), the Arduino also has a 3.3V pin available.

Ground (GND):
Connect the ground of your external circuit (TTL signal ground) to one of the GND pins on the Arduino Uno.

Connections Summary:
TTL Signal (Input):
Connect the TTL signal to digital pin 2.
Connect the ground of the TTL signal to GND on the Arduino.

Output Lines:
Connect digital pin 3 to the device or circuit where you want to output Line 1 (first signal).
Connect digital pin 4 to the device or circuit where you want to output Line 2 (second signal).

Power:
If you're using external hardware that requires 5V, you can connect the 5V pin of the Arduino to the power supply of your circuit.
Make sure the ground of all components is connected to one of the GND pins on the Arduino.



Explanation:

Timing for Output Line 1:
When the input TTL signal goes HIGH, output line 1 starts pulsing at 40 Hz for 500 ms (i.e., it completes 20 pulses during that time).

Timing for Output Line 2:
After a 500 ms delay, output line 2 starts pulsing at 40 Hz for 500 ms (also completing 20 pulses).

Pulsing Behavior:
Output Line 1 will immediately pulse with a frequency of 40 Hz for 500 ms.
Output Line 2 will pulse with a delay of 500 ms after the input signal is HIGH, but also at 40 Hz for 500 ms.
