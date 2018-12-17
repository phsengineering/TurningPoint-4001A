#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, I2C_1,  leftQuad,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightQuad,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           DriveRight_2,  tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           DriveRight_1,  tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           DriveLeft_1,   tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           DriveLeft_2,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           flywheel1,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           flywheel2,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           frontRoller,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           flywheel3,     tmotorServoContinuousRotation, openLoop, reversed)
task fullAllMotors() {
	motor[DriveLeft_1] = 120;
	motor[DriveLeft_2] = 120;
	motor[DriveRight_1] = 120;
	motor[DriveRight_2] = 120;
}
task fullReverse() {
	motor[DriveLeft_1] = -100;
	motor[DriveLeft_2] = -100;
	motor[DriveRight_1] = -100;
	motor[DriveRight_2] = -100;
}
task stopMotors() {
	motor(DriveLeft_1) = 0;
	motor(DriveLeft_2) = 0;
	motor(DriveRight_1) = 0;
	motor(DriveRight_1) = 0;

}

task main() {
	SensorValue[rightQuad] = 0;
	SensorValue[gyro] = 0;
	SensorValue[leftQuad] = 0;
	//motor[flywheel1] = -75;
	//motor[flywheel2] = -75;
	//motor[flywheel3] = -75;
	//motor[frontRoller] = 127;
	//wait(3);
	//		for(int i = 0; i != 0; i++) {
	//			motor[flywheel1] = i;
	//			motor[flywheel2] = i;
	//			motor[flywheel3] = i;
	//			motor[frontRoller] = 0;
	//			wait1Msec(20);
	//		}


	while(SensorValue[leftQuad] < 1560) {
		startTask(fullAllMotors);
	}
	startTask(stopMotors);
	wait(.5);
	while(SensorValue[leftQuad] > -225) {
		startTask(fullReverse);
}
	wait(.1);
	startTask(fullAllMotors);
	wait(.1);
	startTask(stopMotors);
	//wait(.5);
	//left 324
	//right 231
	//left before -440      -177   127
	//right before -638     -537    487
	//SensorValue[leftQuad] = 0;
	//SensorValue[rightQuad] = 0;
	//SensorValue[gyro] = 0;
	while(SensorValue[gyro] > -1970)
	{
		motor[DriveLeft_1] = -80;
		motor[DriveLeft_2] = -80;
		motor[DriveRight_1] = 80;
		motor[DriveRight_2] = 80;
	}
	//motor[DriveLeft_1] = 120;
	//motor[DriveLeft_2] = 120;
	//motor[DriveRight_1] = -120;
	//motor[DriveRight_2] = -120;
	//wait(0.25);
	//startTask(stopMotors);
	//SensorValue[leftQuad] = 0;
	//SensorValue[rightQuad] = 0;
	//while (SensorValue[leftQuad]<1300)
	//{
	//	motor[DriveLeft_1] = 80;
	//	motor[DriveLeft_2] = 80;
	//	motor[DriveRight_1] = 80;
	//	motor[DriveRight_2] = 80;
	//}
	//startTask(stopMotors);
	////left 822
	//right -601
}
