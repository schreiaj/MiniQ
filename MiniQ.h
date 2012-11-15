/*
  MiniQ.h - Library for controlling the MiniQ line of robots from dfRobotics
  Created by Andrew Schreiber Nov 14 2012
  Released into the public domain.
*/

#ifndef MINIQ_Q
#define MINIQ_Q 

#include "Arduino.h"


#define RX	0
#define TX	1
#define LEFT_ENCODER	2
#define RIGHT_ENCODER	3
#define LEFT_MOTOR_DIRECTION_PIN	4
#define LEFT_MOTOR_ENABLE_PIN	5
#define RIGHT_MOTOR_ENABLE_PIN	6
#define RIGHT_MOTOR_DIRECTION_PIN	7
#define INFRARED_RECEIVER	8
#define LEFT_INFARED_TRANSMITTER	9
#define RIGHT_INFRARED_TRANSMITTER	10
#define BUZZER	11
#define RED_LED	12
#define GREEN_LED	13
#define LINE_TRACKING_SENSOR	0
#define LINE_TRACKING_SENSOR	1
#define LINE_TRACKING_SENSOR	2
#define LINE_TRACKING_SENSOR	3
#define AMBIENT_LIGHT_SENSOR	4
#define THREE_KEY_BUTTONS	5
#define RESET_BUTTON	6
#define LINE_TRACKING_SENSOR	7

void rightEncoderISR(void);
void leftEncoderISR(void);
long getLeftEncoder(void);
long getRightEncoder(void);
void resetLeftEncoder(void);
void resetRightEncoder(void);


class MiniQ
{

public:
	MiniQ();
	void setRedLED(int on);
	void setGreenLED(int on);
	void setLeftMotor(int speed);
	void setRightMotor(int speed);
	int  getAmbientLight(void);
	void enableLeftInterrupt(void);
	void enableRightInterrupt(void);

};




#endif