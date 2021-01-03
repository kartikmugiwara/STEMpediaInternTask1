#include "Arduino.h"
#include "PWM.h"

pwm pwmChannels[16]={
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	{-1,5000,8},
	};

int getChannel(uint8_t pin)
{
  int channel = -1;

  // Checking if any channel is connected with pin
  for (uint8_t i = 0; i < 16; i++)
  {
    if (pwmChannels[i].pin == pin)
    {
      channel = i;
      break;
    }
  }

  // WIll enter this only if there is no channel attached to pin
  if (channel == -1)
  {
    for (uint8_t i = 0; i < 16; i++)
    {
      if (pwmChannels[i].pin == -1) 
      //if any channel is free, attach to pin
      {
        pwmChannels[i].pin = pin;
        channel = i;
        ledcSetup(channel, pwmChannels[i].frequency, pwmChannels[i].resolution);
        ledcAttachPin(pin, channel);
        break;
      }
    }
  }

  return channel;
}

void setAllFrequency(double frequency) 
// set common frequency for all channels
{
  for (uint8_t i = 0; i < 16; i++)
  {
    pwmChannels[i].frequency = frequency;
  }
}

void setPinFrequency(uint8_t pin, double frequency)
//set frequency of a pin which has channel attached
{
  int channel = getChannel(pin);

  // Change frequency only if pin is attached to a channel
  if (channel != -1 && channel < 16)
  {
    pwmChannels[channel].frequency = frequency;
  }
}

void setAllResolution(uint8_t resolution)
//set resolution of all channels to a common value
{
  for (uint8_t i = 0; i < 16; i++)
  {
    pwmChannels[i].resolution = resolution;
  }
}

void setPinResolution(uint8_t pin, uint8_t resolution)
//set resolution of the channel attached to the specific pin
{
  int channel = getChannel(pin);
  
  if (channel != -1 && channel < 16)
  {
    pwmChannels[channel].resolution = resolution;
  }
}

void setPWM(uint8_t pin, uint32_t value, uint32_t valueMax)
// setup PWM on the specific pin 
{
  int channel = getChannel(pin);

  // Make sure the pin was attached to a channel
  if (channel != -1 && channel < 16)
  {
    uint8_t resolution = pwmChannels[channel].resolution;
    uint32_t duty = (((pow(2,resolution)) - 1) / valueMax) * min(value, valueMax);

    ledcWrite(channel, duty);
  }
}
