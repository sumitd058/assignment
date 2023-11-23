#include <TimerOne.h>
#include <stdint.h>

const uint8_t lm35Pin = A0;       // LM35 sensor connected to analog pin A0
const uint8_t ledPin = 13;        // Onboard LED connected to digital pin 13
const uint8_t tempThreshold = 30; // Temperature threshold in degrees Celsius

const uint32_t intervalLowTemp = 250;  // Blink interval for low temperature
const uint32_t intervalHighTemp = 500; // Blink interval for high temperature

void setup()
{
    pinMode(lm35Pin, INPUT); // Take lm35Pin as input mode  for reading data
    pinMode(ledPin, OUTPUT); // Take ledPin as ouput mode

    // Set up the TimerOne library
    Timer1.initialize(1000);          // Set timer interval to 1000 microseconds (1ms)
    Timer1.attachInterrupt(timerISR); // Timer interrupt
}

void loop()
{
    // This loop is intentionally left empty.
}

// Timer1 ISR(interrupt service routine)
void timerISR()
{
    uint32_t temperature = readTemperature();

    if (temperature < tempThreshold)
    {
        blinkLED(intervalLowTemp);
    }
    else
    {
        blinkLED(intervalHighTemp);
    }
}

// These function read temperature value
uint32_t readTemperature()
{
    uint32_t sensorValue = analogRead(lm35Pin); // Read the analog value from LM35 sensor

    // Convert analog value to temperature in degrees Celsius
    float voltage = (sensorValue / 1023.0) * 5.0;
    uint32_t temperature = (voltage - 0.5) * 100.0;
    return temperature;
}

// These function use for blinking led
void blinkLED(long interval)
{
    // Toggle the LED state
    if (digitalRead(ledPin) == HIGH)
    {
        digitalWrite(ledPin, LOW);
    }

    else
    {
        digitalWrite(ledPin, HIGH);
    }

    // Set the timer interval for the next LED state change
    Timer1.setPeriod(interval * 1000); // Convert milliseconds to microseconds because it takes input in microseconds
}
