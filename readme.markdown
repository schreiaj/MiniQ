# MiniQ Arduino Library

The purpose of this library is to allow easy control of the 2WD MiniQ. 

## Supported Features

### Driving

Currently, driving is done by two functions, one for each wheel.

```cpp
	void setLeftMotor(int speed);
	void setRightMotor(int speed);
```

Speeds are from -255 to +255 with 0 being stopped. As a warning, the deadbands for these motors are quite broad pretty much anything less than 40 either way won't move the robot... of course that depends on your battery voltage. 

### LEDs

Good news, the Red and Green LEDS on the front of the robot can be controlled pretty easily. Currently we only support turning them on and off. They can be controlled with the functions called

```cpp
	void setRedLED(int on);
	void setGreenLED(int on);
```

You can also vary the brightness of these LEDs by using ``` analogWrite(RED_LED,value)``` or ```cpp analogWrite(GREEN_LED,value)```. These may be integrated into functions in the future. 

The bad news? Those annoying blue LEDs that everyone seems to put on electronics? Those are there to stay, I haven't found how to control those yet since I don't think they are tied to a control line. 


### Sensors

Currently the only sensor functioning is the Ambient Light Sensor. You can read the value with ``` getAmbientLight() ``` which will give you an int value between 0 and 1024.
