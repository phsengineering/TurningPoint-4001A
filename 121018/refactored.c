#pragma config(Sensor, in5,    gyro,           sensorGyro)
#pragma config(Sensor, I2C_1,  leftQuad,       sensorNone)
#pragma config(Sensor, I2C_2,  rightQuad,      sensorNone)
#pragma config(Motor,  port2,           DriveRight_2,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           DriveLeft_1,   tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           DriveLeft_2,   tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           DriveRight_1,  tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//left 1564
//right -1483
//left -727
//right 709
//left -719
//right 724
//left -716  avg -721
//right 718  avg 717

#define     JOY_DRIVE_V     vexJSLeftV
#define     JOY_DRIVE_H     vexJSLeftH
#define     JOY_THRESHOLD   15


#define MOTOR_NUM               kNumbOfTotalMotors
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 10      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    256     // essentially off
#define MOTOR_TASK_DELAY        15      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          10

// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ];

// Array to hold "slew rate" for the motors, the maximum change every time the task
// runs checking current mootor speed.
int motorSlew[ MOTOR_NUM ];
task fullAllMotors() {
		motor[DriveLeft_1] = 120;
		motor[DriveLeft_2] = 120;
		motor[DriveRight_1] = 120;
		motor[DriveRight_2] = 120;
	}
task fullReverse() {
	motor[DriveLeft_1] = -120;
		motor[DriveLeft_2] = -120;
		motor[DriveRight_1] = -120;
		motor[DriveRight_2] = -120;
	}
task stopMotors() {
	stopMotor(DriveLeft_1);
	stopMotor(DriveLeft_2);
	stopMotor(DriveRight_1);
	stopMotor(DriveRight_2);
}
task autonomous() {
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] < 1560) {
		startTask(fullAllMotors);
	}
	startTask(stopMotors);
	wait(.5);
	while(SensorValue[leftQuad] > -175) {
		startTask(fullReverse);
	}
	wait(.25);
	startTask(fullAllMotors);
	wait(.5);
	startTask(stopMotors);
	wait(.5);
	//left 324
	//right 231
	//left before -440      -177   127
	//right before -638     -537    487
	SensorValue[leftQuad] = 0;
	SensorValue[rightQuad] = 0;
	SensorValue[gyro] = 0;
	while(SensorValue[gyro] < 900)
	{
		motor[DriveLeft_1] = -80;
		motor[DriveLeft_2] = -80;
		motor[DriveRight_1] = 80;
		motor[DriveRight_2] = 80;
	}
	motor[DriveLeft_1] = 120;
	motor[DriveLeft_2] = 120;
	motor[DriveRight_1] = -120;
	motor[DriveRight_2] = -120;
	wait(0.25);
	startTask(stopMotors);
	SensorValue[leftQuad] = 0;
	SensorValue[rightQuad] = 0;
	while (SensorValue[leftQuad]<1300)
	{
		motor[DriveLeft_1] = 80;
		motor[DriveLeft_2] = 80;
		motor[DriveRight_1] = 80;
		motor[DriveRight_2] = 80;
	}
	startTask(stopMotors);
		//left 822
		//right -601
	}




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
			ctl_h = vexRT[ JOY_DRIVE_H ];

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



	task main()
	{
  //UNTESTED
		//SensorType[in5] = sensorNone;
		//wait1Msec(1);
		//SensorType[in5] = sensorGyro;
		startTask(autonomous);

		// Start motor slew rate control
		startTask( MotorSlewRateTask );

		// Start driver control tasks
		startTask( ArcadeDrive );

		// Everything done in other tasks
		while( true )
		{
			wait1Msec( 100 );
		}
	}