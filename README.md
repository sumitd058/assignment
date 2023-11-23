# Problem statement
Develop the code in Arduino to interface an LM35 temperature
sensor (Assume the sensor is connected to Arduino Analog pin A0) with an Arduino
Uno and control the onboard LED based on temperature readings:
1. Interface the LM35 temperature sensor with an Arduino Uno.
2. When the temperature falls below 30 degrees Celsius, make the onboard LED
blink every 250 milliseconds.
3. If the temperature rises above 30 degrees Celsius, make the onboard LED blink
every 500 milliseconds.
Note :- You are not supposed use Millis(), delay() and micros() function and you can
use any library to perform this task.

******************************************************************************************************************************************************************************************************
# Temperature-Dependent LED Blinking System

## Components Required
1. Arduino Uno
2. LM35 Temperature Sensor
3. Jumper Wires

## Circuit Wiring
1. Connect the LM35 sensor's output to Arduino's Analog Pin A0.
2. Connect the LM35 sensor's VCC pin to Arduino's 5V pin.
3. Connect the LM35 sensor's GND pin to Arduino's GND pin.
4. Connect the onboard LED to Arduino's digital Pin 13.

## Functionality
- The onboard LED blinks every 250 milliseconds if the temperature falls below 30 degrees Celsius.
- The onboard LED blinks every 500 milliseconds if the temperature rises above 30 degrees Celsius.

## Usage
1. Set up the circuit as per the wiring instructions.
2. Upload the `assignment.ino` code to your Arduino Uno.

## Dependencies
- **TimerOne Library:** Ensure you have the TimerOne library installed in your Arduino IDE.

## Code Explanation
- The main code is in the `assignment.ino` file.
- The Timer1 library is used to handle timer interrupts for LED blinking.
- Temperature readings are obtained from the LM35 sensor using the `readTemperature` function.
- The onboard LED is controlled based on temperature thresholds in the `timerISR` function.
- The `blinkLED` function toggles the LED state and sets the timer interval for the next LED state change.

## Author
- Sum
