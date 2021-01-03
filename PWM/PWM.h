#ifndef ESP32_PWM
#define ESP32_PWM

#include <Arduino.h>
class pwm
{
	public:
		int pin,frequency,resolution;
};

int getChannel(uint8_t pin);

void setAllFrequency(double frequency);
void setPinFrequency(uint8_t pin, double frequency);

void setAllResolution(uint8_t resolution);
void setPinResolution(uint8_t pin, uint8_t resolution);

void setPWM(uint8_t pin, uint32_t value, uint32_t valueMax = 255);

#endif
