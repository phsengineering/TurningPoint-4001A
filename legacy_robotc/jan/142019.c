#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, I2C_1,  rightQuad,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftQuad,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           DriveRight_2,  tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           DriveRight_1,  tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           DriveLeft_1,   tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           DriveLeft_2,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           flywheel1,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           flywheel2,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           frontRoller,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           flywheel3,     tmotorServoContinuousRotation, openLoop, reversed)

task fullAllMotors() {
	motor[DriveLeft_1] = 127;
	motor[DriveLeft_2] = 127;
	motor[DriveRight_1] = 127;
	motor[DriveRight_2] = 127;
}
task fullReverse() {
	motor[DriveLeft_1] = -127;
	motor[DriveLeft_2] = -127;
	motor[DriveRight_1] = -127;
	motor[DriveRight_2] = -127;
}
task stopMotors() {
	motor(DriveLeft_1) = 0;
	motor(DriveLeft_2) = 0;
	motor(DriveRight_1) = 0;
	motor(DriveRight_1) = 0;

}

task main() {

	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[rightQuad] < 1250) {
		startTask(fullAllMotors);
		motor[frontRoller] = 100;
	}

	startTask(fullReverse);
	wait(.25);
	//startTask(stopMotors);
	//wait(2);
	while(SensorValue[rightQuad] > 0) {
		startTask(fullReverse);
	}
	//startTask(fullAllMotors);
	//wait(.25);
	motor[frontRoller] = 0;
	startTask(stopMotors);
	SensorValue[rightQuad] = 0;
	while(SensorValue[rightQuad] < 200) {
		motor[DriveLeft_1] = 50;
		motor[DriveLeft_2] = 50;
	  motor[DriveRight_1] = -50;
	  motor[DriveRight_2] = -50;
	}
	startTask(stopMotors);
	SensorValue[rightQuad] = 0;
	//motor[flywheel1] = -127;
	//motor[flywheel2] = -127;
	//motor[flywheel3] = -127;
	//wait(3);
	//motor[frontRoller] = -127;
	//wait(2);
	//motor[flywheel1] = 0;
	//motor[flywheel2] = 0;
	//motor[flywheel3] = 0;
	//motor[frontRoller] = 0;
	while(SensorValue[rightQuad] < 780) {
		startTask(fullAllMotors);
	}
	startTask(fullReverse);
	wait(.25);
	startTask(stopMotors);
	while(SensorValue[rightQuad] > 75) {
		motor[DriveLeft_1] = -50;
		motor[DriveLeft_2] = -50;
		motor[DriveRight_1] = 50;
		motor[DriveRight_2] = 50;
	}
	motor[DriveLeft_1] = 50;
		motor[DriveLeft_2] = 50;
		motor[DriveRight_1] = -50;
		motor[DriveRight_2] = -50;
		wait(.3);
	//startTask(fullReverse);
	//wait(.25);
	startTask(stopMotors);
	wait(.25);
	startTask(fullReverse);
	wait(.5);
	startTask(fullAllMotors);
	wait(2.25);
	startTask(stopMotors);
}
