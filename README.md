# STEMpediaInternTask1

# About
This library helps in setting up PWM on different pins of ESP32 in Arduino IDE without worrying about the channel allocation for different pins.

# Usage
There are different functions available inside the library which help in setting up the ESP32 GPIO pins for PWM just like the analogWrite function available for Arduino. 

Just include the PWM library folder inside the libraries directory for your ESP32 and you can use the functions by including "PWM.h" in your sketch.

### Allocation of Channel for PWM 
```cpp
int getChannel(uint8_t pin) //allocates a channel to the pin from the 16 available channels in ESP32 and returns the channel number
```
### Frequency and Resolution of Duty Cycle
You can set a common frequency for all channels or change individual channel's frequency
```cpp
void setAllFrequency(5000);   // sets frequency of all channels as 5KHz
void setPinFrequency(2,5000); // sets frequency of pin 2 as 5KHz
```
Similarly, one can also adjust the resolution of duty cycle but care must be taken in duty cycle calculation as both frequency and duty cycle are interdependent.
```cpp
void setAllResolution(10);    // set timer resolution for all channels to be of 10 bits
void setPinResolution(2,10);  // set timer resolution of channel allocated to pin 2 to be of 10 bits
```
After setting frequency and duty cycle for the pin, one can start PWM on the pin by using `setPWM()`. If no channel is allocated then the function will itself allocate a free channel with default resolution and frequency (8bits & 5000Hz).
```cpp
void setPWM(2,127); // Observe PWM on pin 2 with 50% duty cycle as default resolution is 8 bits i.e 255 values
```
# Example
As instructed, PWM on pin 2 was setup using the library functions and the result was recorded and the video is included in the repo.
