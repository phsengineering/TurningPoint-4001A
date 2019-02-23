#pragma once
#include "main.h"

extern Motor frontLeft;
extern Motor backLeft;
extern Motor frontRight;
extern Motor backRight;
extern Vision vision_sensor;
extern int auton;
void drive(int y, int r);
void autoDrive(int x);
void autoReset();
void resetEncoders();
extern Motor liftMotor;
void setLift(int speed);

extern Motor flywheel;
void setFlywheel(int velocity);

extern Motor indexer;
void setIndexer(int speed);
extern Motor intake;
void setIntake(int speed);
