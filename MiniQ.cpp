#include "Arduino.h"
#include "MiniQ.h"

long _rightEncoder, _leftEncoder;

void rightEncoderISR(void)
{
	_rightEncoder++;
}

void leftEncoderISR(void)
{
	_leftEncoder++;
}

long getLeftEncoder()
{
	return _leftEncoder;
}

long getRightEncoder()
{
	return _rightEncoder;
}

void resetLeftEncoder()
{
	_leftEncoder = 0;
}
void resetRightEncoder()
{
	_rightEncoder = 0;
}

MiniQ::MiniQ()
{
	
	// here we set the motors to all be output pins
	pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);
	pinMode(LEFT_MOTOR_ENABLE_PIN, OUTPUT);
	pinMode(RIGHT_MOTOR_ENABLE_PIN, OUTPUT);
	pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);

	// here we set the LED pins to be outputs
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
}


void MiniQ::setRedLED(int on)
{
	digitalWrite(RED_LED, on);
}

void MiniQ::setGreenLED(int on)
{
	digitalWrite(GREEN_LED, on);
}

void MiniQ::setLeftMotor(int speed)
{
	analogWrite(LEFT_MOTOR_ENABLE_PIN, speed);
	digitalWrite(LEFT_MOTOR_DIRECTION_PIN, speed > 0);
}
void MiniQ::setRightMotor(int speed)
{
	analogWrite(RIGHT_MOTOR_ENABLE_PIN, speed);
	digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, speed > 0);
}

int MiniQ::getAmbientLight(void)
{
	return analogRead(AMBIENT_LIGHT_SENSOR);
}

void MiniQ::enableLeftInterrupt(void)
{
	attachInterrupt(0, leftEncoderISR, CHANGE);
}
void MiniQ::enableRightInterrupt(void)
{
	attachInterrupt(1, rightEncoderISR, CHANGE);
}

