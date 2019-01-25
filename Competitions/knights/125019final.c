#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in8,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl3,  descorerLimit,  sensorTouch)
#pragma config(Sensor, I2C_1,  rightQuad,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftQuad,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           DriveLeft_1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           DriveLeft_2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           DriveRight_1,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           DriveRight_2,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           indexer,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontRoller,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           descorer,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           flywheel,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify
#pragma platform(VEX2)
static int count = 0;

// Select Download method as "competition"


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void move(int uniformSpeed) {
	motor[DriveLeft_1] = uniformSpeed;
	motor[DriveLeft_2] = uniformSpeed;
	motor[DriveRight_1] = uniformSpeed;
	motor[DriveRight_2] = uniformSpeed;
}
task turn90() {
	while((SensorValue[in8]) < 900)
	{
		//...continue turning
		motor[DriveRight_1] = -60;
		motor[DriveRight_2] = -60;
		motor[DriveLeft_1] = 60;
		motor[DriveLeft_2] = 60;
	}

	//Brief brake to stop some drift
	motor[DriveRight_1] = 60;
	motor[DriveRight_2] = 60;
	motor[DriveLeft_1] = -60;
	motor[DriveLeft_2] = -60;
	wait1Msec(139);
	move(0);
	wait(.75);
}
task turnother90() {
	while((SensorValue[in8]) > -900)
	{
		//...continue turning
		motor[DriveRight_1] = 60;
		motor[DriveRight_2] = 60;
		motor[DriveLeft_1] = -60;
		motor[DriveLeft_2] = -60;
	}

	//Brief brake to stop some drift
	motor[DriveRight_1] = -60;
	motor[DriveRight_2] = -60;
	motor[DriveLeft_1] = 60;
	motor[DriveLeft_2] = 60;
	wait1Msec(139);
	move(0);
	wait(.75);
}
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
void pre_auton()
{
	//Declare count variable to keep track of our choice

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Red front");
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Red back");
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Blue Front");
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Blue back");
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


task autonomous() {
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice

	{

		switch(count){
		case 0:
			//If count = 0, run the code correspoinding with choice 1
			displayLCDCenteredString(0, "Red front");
			displayLCDCenteredString(1, "is running!");
			SensorValue[leftQuad] = 0;
			motor[flywheel] = -127;
			while(SensorValue[leftQuad] < 1100) {
				move(100);
				motor[frontRoller] = 127;
			}
			move(0);
			wait(.1);
			move(-127);
			wait(.15);
			move(0);
			motor[frontRoller] = 127;
			wait(.25);
			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] > -1055)
			{
				move(-63);
			}
			motor[flywheel] = -127;
			move(100);
			wait(.1);
			move(0);
			wait(.15);
			SensorValue[leftQuad]=0;
			SensorValue[gyro] = 0;
			startTask(turn90);
			wait(1);

			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] < 145)
				{
				move(60);
			}
			move(0);
			wait(.75);
			motor[indexer] = 127;
			wait(1);
			motor[indexer] = 0;

			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] < 325) {   //middle flag
				move(60);
			}
			move(0);
			motor[indexer] = 127;
			wait(.75);
			motor[frontRoller] = 127;
			wait(0.9);
			motor[frontRoller] = 0;
			motor[indexer] = 0;
			move(0);
			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] > -1555) {
				move(-127);
			}
			move(0);
			wait(.2);
			move(127);
			wait(.15);
			move(0);
			wait(.25);
			SensorValue[leftQuad] = 0;
			SensorValue[gyro] = 0;
			while((SensorValue[in8]) > -900)
			{
				//...continue turning
				motor[DriveRight_1] = 60;
				motor[DriveRight_2] = 60;
				motor[DriveLeft_1] = -60;
				motor[DriveLeft_2] = -60;
			}

			//Brief brake to stop some drift
			motor[DriveRight_1] = -60;
			motor[DriveRight_2] = -60;
			motor[DriveLeft_1] = 60;
			motor[DriveLeft_2] = 60;
			wait1Msec(139);
			move(0);

			move(-127);
			wait(0.75);
			move(127);
			wait(2);
			move(0);
			//Put in code here directly without braces
			break;
		case 1:
			//If count = 1, run the code correspoinding with choice 2
			displayLCDCenteredString(0, "Red back");
			displayLCDCenteredString(1, "is running!");
						SensorValue[leftQuad] = 0;
			motor[flywheel] = -127;
			while(SensorValue[leftQuad] < 1100) {
				move(100);
				motor[frontRoller] = 127;
			}
			move(0);
			wait(.1);
			move(-127);
			wait(.15);
			move(0);
			motor[frontRoller] = 127;
			wait(.25);
			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] > -1055)
			{
				move(-63);
			}
			motor[flywheel] = -127;
			move(100);
			wait(.1);
			move(0);
			wait(.15);
			SensorValue[leftQuad]=0;
			SensorValue[gyro] = 0;
			while((SensorValue[in8]) < 900)
	{
		//...continue turning
		motor[DriveRight_1] = -60;
		motor[DriveRight_2] = -60;
		motor[DriveLeft_1] = 60;
		motor[DriveLeft_2] = 60;
	}

	//Brief brake to stop some drift
	motor[DriveRight_1] = 50;
	motor[DriveRight_2] = 50;
	motor[DriveLeft_1] = -50;
	motor[DriveLeft_2] = -50;
	wait1Msec(120);
	move(0);
			wait(1);

			SensorValue[leftQuad] = 0;

			while(SensorValue[leftQuad] < 795) {
				move(60);
			}
			move(-60);
			wait(.25);
			move(0);
			motor[frontRoller] = 127;
			motor[indexer] = 127;
			wait(3);
			motor[frontRoller] = 0;
			motor[indexer] = 0;
						SensorValue[leftQuad] = 0;
			SensorValue[gyro] = 0;
			while((SensorValue[in8]) > -900)
			{
				//...continue turning
				motor[DriveRight_1] = 60;
				motor[DriveRight_2] = 60;
				motor[DriveLeft_1] = -60;
				motor[DriveLeft_2] = -60;
			}

			//Brief brake to stop some drift
			motor[DriveRight_1] = -60;
			motor[DriveRight_2] = -60;
			motor[DriveLeft_1] = 60;
			motor[DriveLeft_2] = 60;
			wait1Msec(134);
			move(0);
			wait(.5);
			move(-127);
			wait(.5);
			move(0);
			wait(.1);
			move(127);
			wait(2);
			move(0);
			motor[flywheel] = 0;
			break;
		case 2:
			//If count = 2, run the code correspoinding with choice 3
			displayLCDCenteredString(0, "Blue front");
			displayLCDCenteredString(1, "is running!");
			SensorValue[leftQuad] = 0;
			motor[flywheel] = -127;
			while(SensorValue[leftQuad] < 1100) {
				move(100);
				motor[frontRoller] = 127;
			}
			move(0);
			wait(.1);
			move(-127);
			wait(.15);
			move(0);
			motor[frontRoller] = 127;
			wait(.25);
			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] > -1055)
			{
				move(-63);
			}
			motor[flywheel] = -127;
			move(100);
			wait(.1);
			move(0);
			wait(.15);
			SensorValue[leftQuad]=0;
			SensorValue[gyro] = 0;
			startTask(turnother90);
			wait(1);

			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] < 145)
				{
				move(60);
			}
			move(0);
			wait(.75);
			motor[indexer] = 127;
			wait(1);
			motor[indexer] = 0;

			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] < 325) {   //middle flag
				move(60);
			}
			move(0);
			motor[indexer] = 127;
			wait(.75);
			motor[frontRoller] = 127;
			wait(0.9);
			motor[frontRoller] = 0;
			motor[indexer] = 0;
			move(0);
			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] > -1555) {
				move(-127);
			}
			move(0);
			wait(.2);
			move(127);
			wait(.15);
			move(0);
			wait(.25);
			SensorValue[leftQuad] = 0;
			SensorValue[gyro] = 0;
			while((SensorValue[in8])< 900)
			{
				//...continue turning
				motor[DriveRight_1] = -60;
				motor[DriveRight_2] = -60;
				motor[DriveLeft_1] = 60;
				motor[DriveLeft_2] = 60;
			}

			//Brief brake to stop some drift
			motor[DriveRight_1] = 60;
			motor[DriveRight_2] = 60;
			motor[DriveLeft_1] = -60;
			motor[DriveLeft_2] = -60;
			wait1Msec(139);
			move(0);

			move(-127);
			wait(0.75);
			move(127);
			wait(2);
			move(0);
			//Put in code here directly without braces
			break;
		case 3:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "Blue back");
			displayLCDCenteredString(1, "is running!");
			SensorValue[leftQuad] = 0;
			motor[flywheel] = -127;
			while(SensorValue[leftQuad] < 1100) {
				move(100);
				motor[frontRoller] = 127;
			}
			move(0);
			wait(.1);
			move(-127);
			wait(.15);
			move(0);
			motor[frontRoller] = 127;
			wait(.25);
			SensorValue[leftQuad] = 0;
			while(SensorValue[leftQuad] > -1055)
			{
				move(-63);
			}
			motor[flywheel] = -127;
			move(100);
			wait(.1);
			move(0);
			wait(.15);
			SensorValue[leftQuad]=0;
			SensorValue[gyro] = 0;
			while((SensorValue[in8]) > -900)
	{
		//...continue turning
		motor[DriveRight_1] = 60;
		motor[DriveRight_2] = 60;
		motor[DriveLeft_1] = -60;
		motor[DriveLeft_2] = -60;
	}

	//Brief brake to stop some drift
	motor[DriveRight_1] = -50;
	motor[DriveRight_2] = -50;
	motor[DriveLeft_1] = 50;
	motor[DriveLeft_2] = 50;
	wait1Msec(120);
	move(0);
			wait(1);

			SensorValue[leftQuad] = 0;

			while(SensorValue[leftQuad] < 795) {
				move(60);
			}
			move(-60);
			wait(.25);
			move(0);
			motor[frontRoller] = 127;
			motor[indexer] = 127;
			wait(3);
			motor[frontRoller] = 0;
			motor[indexer] = 0;
						SensorValue[leftQuad] = 0;
			SensorValue[gyro] = 0;
			while((SensorValue[in8])< 900)
			{
				//...continue turning
				motor[DriveRight_1] = -60;
				motor[DriveRight_2] = -60;
				motor[DriveLeft_1] = 60;
				motor[DriveLeft_2] = 60;
			}

			//Brief brake to stop some drift
			motor[DriveRight_1] = 60;
			motor[DriveRight_2] = 60;
			motor[DriveLeft_1] = -60;
			motor[DriveLeft_2] = -60;
			wait1Msec(134);
			move(0);
			wait(.5);
			move(-127);
			wait(.5);
			move(0);
			wait(.1);
			move(127);
			wait(2);
			move(0);
			motor[flywheel] = 0;
			break;
		//case 4:
		//	//If count = 0, run the code correspoinding with choice 1
		//	displayLCDCenteredString(0, "BlueCF");
		//	displayLCDCenteredString(1, "is running!");
		//	//Put in code here directly without braces
		//	break;
		//case 5:
		//	//If count = 1, run the code correspoinding with choice 2
		//	displayLCDCenteredString(0, "BlueCFP");
		//	displayLCDCenteredString(1, "is running!");
		//	//Put in code here directly without braces
		//	break;
		//case 6:
		//	//If count = 2, run the code correspoinding with choice 3
		//	displayLCDCenteredString(0, "BlueBCFP");
		//	displayLCDCenteredString(1, "is running!");
		//	//Put in code here directly without braces
		//	break;
		//case 7:
		//	//If count = 3, run the code correspoinding with choice 4
		//	displayLCDCenteredString(0, "BlueBCF");
		//	displayLCDCenteredString(1, "is running!");
		//	//Put in code here directly without braces
		//	break;
		//case 8:
		//	//If count = 3, run the code correspoinding with choice 4
		//	displayLCDCenteredString(0, "ProgramSkills");
		//	displayLCDCenteredString(1, "is running!");
		//	//Put in code here directly without braces
		//	break;
		default:
			displayLCDCenteredString(0, "No Auton");
			displayLCDCenteredString(1, "Selected");
			break;
		}
	}
}
#define     JOY_DRIVE_V     vexJSLeftV
#define     JOY_DRIVE_H     vexJSLeftH
#define     JOY_THRESHOLD   15


#define MOTOR_NUM               kNumbOfTotalMotors
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 9      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    250     // essentially off
#define MOTOR_TASK_DELAY        10      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          9

// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ];

// Array to hold "slew rate" for the motors, the maximum change every time the task
// runs checking current mootor speed.
int motorSlew[ MOTOR_NUM ];
task MotorSlewRateTask()
{
	int motorIndex;
	int motorTmp;

	// Initialize stuff
	for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++)
	{
		motorReq[motorIndex] = 0;
		motorSlew[motorIndex] = MOTOR_DEFAULT_SLEW_RATE;
	}

	// run task until stopped
	while( true )
	{
		// run loop for every motor
		for( motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++)
		{
			// So we don't keep accessing the internal storage
			motorTmp = motor[ motorIndex ];

			// Do we need to change the motor value ?
			if( motorTmp != motorReq[motorIndex] )
			{
				// increasing motor value
				if( motorReq[motorIndex] > motorTmp )
				{
					motorTmp += motorSlew[motorIndex];
					// limit
					if( motorTmp > motorReq[motorIndex] )
						motorTmp = motorReq[motorIndex];
				}

				// decreasing motor value
				if( motorReq[motorIndex] < motorTmp )
				{
					motorTmp -= motorSlew[motorIndex];
					// limit
					if( motorTmp < motorReq[motorIndex] )
						motorTmp = motorReq[motorIndex];
				}

				// finally set motor
				motor[motorIndex] = motorTmp;
			}
		}

		// Wait approx the speed of motor update over the spi bus
		wait1Msec( MOTOR_TASK_DELAY );
	}
}


void
DriveLeftMotor( int value )
{
	motorReq[ DriveLeft_1 ] = value;
	motorReq[ DriveLeft_2 ] = value;
}


void
DriveRightMotor( int value )
{
	motorReq[ DriveRight_1 ] = value;
	motorReq[ DriveRight_2 ] = value;
}


task PlatformDrive ()//to get onto the platform at the end of the match
{
	if(vexRT[Btn8U] == 1) {
		motor[DriveLeft_1] = 127;
		motor[DriveLeft_2] = 127;
		motor[DriveRight_1] = 127;
		motor[DriveRight_2] = 127;
	}

	if(vexRT[Btn8D] == 1) {
		motor[DriveLeft_1] = -127;
		motor[DriveLeft_2] = -127;
		motor[DriveRight_1] = -127;
		motor[DriveRight_2] = -127;
	}
}
task ArcadeDrive()
{
	int    ctl_v;
	int    ctl_h;
	int    drive_l;
	int    drive_r;

	// Basic arcade control
	while( true )
	{
		// Get joystick H and V control
		ctl_v = vexRT[ JOY_DRIVE_V ];
		ctl_h = -vexRT[ JOY_DRIVE_H ];

		// Ignore joystick near center
		if( (abs(ctl_v) <= JOY_THRESHOLD) && (abs(ctl_h) <= JOY_THRESHOLD) )
		{
			drive_l = 0;
			drive_r = 0;
		}
		else
		{
			// Create drive for left and right motors
			drive_l = (ctl_v + ctl_h) / 2;
			drive_r = (ctl_v - ctl_h) / 2;
		}

		// Now send out to motors
		DriveLeftMotor( drive_l );
		DriveRightMotor( drive_r );

		// don't hog CPU
		wait1Msec( 25 );
	}
}
//task clawControl() {
//	while(true) {
//		if(vexRT[Btn8D] == 1) {
//			motor[clawMotor] = 100;
//		}
//		if(vexRT[Btn8U] == 1) {
//			motor[clawMotor] = -100;
//		}
//	}
//}
task descorerControl() {
	while(true) {
		if(SensorValue[descorerLimit] == 0) {
			motor[descorer] = vexRT[Ch2];
		}
		else {
			if(vexRT[Ch2] > 0) {
				motor[descorer] = -vexRT[Ch2];
			}
			else {
				motor[descorer] = vexRT[Ch2];
			}
		}
	}
}

task frontControl() {
	while(true) {
		if(vexRT[Btn5D] == 1) {
			motor[frontRoller] = 127;
		}
		if(vexRT[Btn6D] == 1) {
			motor[frontRoller] = -127;
		}
	}
}
task flywheelCtrl() {
	while(true) {
		if(vexRT[Btn8DXmtr2] == 1) {

			motor[flywheel] = -127;
		}
		if(vexRT[Btn7DXmtr2] == 1) {
			motor[indexer] = 127;
		}
		if(vexRT[Btn7LXmtr2] == 1) {
			motor[indexer] = -127;
		}
		if(vexRT[Btn5UXmtr2] == 1) {
			motor[frontRoller] = 127;
		}
	}
}

//task liftControl() {
//	while(true) {
//		motor[liftMotors] = vexRT[Ch2];
//	}
//}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop
	startTask(MotorSlewRateTask);
	startTask(ArcadeDrive);
	while (true)
	{
		//startTask(liftControl);
		//startTask(clawControl);
		startTask(flywheelCtrl);
		startTask(frontControl);
		startTask(PlatformDrive);
		startTask(descorerControl);
	}
}
