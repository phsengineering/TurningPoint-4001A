
task main()
{



}
task autonomous() {
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] < 1564) {// starts the movement forward towards low flag from blue front
		motor[DriveLeft_1] = 120;
		motor[DriveLeft_2] = 120;
		motor[DriveRight_1] = 120;
		motor[DriveRight_2] = 120;
	}
	stopMotor(DriveLeft_1);
	stopMotor(DriveLeft_2);
	stopMotor(DriveRight_1);
	stopMotor(DriveRight_2);
	wait(2);// blue flag has been toggeled
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] > -1800) {
		motor[DriveLeft_1] = -100;
		motor[DriveLeft_2] = -100;
		motor[DriveRight_1] = -100;
		motor[DriveRight_2] = -100;
	}// speed reduced on the way back,to reduce drift and glide. The robot lines up in front of the blue alliance platform behind the starting tile at this point
	wait(.25);
	motor[DriveLeft_1] = 120;
	motor[DriveLeft_2] = 120;
	motor[DriveRight_1] = 120;
	motor[DriveRight_2] = 120;
	wait(.5);
	stopMotor(DriveLeft_1);
	stopMotor(DriveLeft_2);
	stopMotor(DriveRight_1);
	stopMotor(DriveRight_2);
	wait(.5);
	// sensorvalue reset to allow for turn
	SensorValue[leftQuad] = 0;
	SensorValue[rightQuad] = 0;
	while(SensorValue[rightQuad]> -570)
	{
		motor[DriveRight_1] = -120;
		motor[DriveRight_2] = -120;// only using one side of the drive train to turn efficiently with low speed and skid
	} wait(0.5);
	motor[DriveLeft_1] = -100;
	motor[DriveLeft_2] = -100;
	motor[DriveRight_1] = -100;
	motor[DriveRight_2] = -100;
	wait(1);
	stopMotor(DriveLeft_1);// robot drives into the wall for halfa second to line itself up straight with the platform after the turn
	stopMotor(DriveLeft_2);
	stopMotor(DriveRight_1);
	stopMotor(DriveRight_2);
	SensorValue[leftQuad] = 0;
	SensorValue[rightQuad] = 0;
	while (SensorValue[leftQuad]<1100)
	{
		motor[DriveLeft_1] = 127;
		motor[DriveLeft_2] = 127;
		motor[DriveRight_1] = 127;
		motor[DriveRight_2] = 127;
	}
	wait(.25);// drives forward at full speed and onto platform
	motor[DriveLeft_1] = -120;
	motor[DriveLeft_2] = -120;
	motor[DriveRight_1] = -120;
	motor[DriveRight_2] = -120;
	wait(.5);
	stopMotor(DriveLeft_1);
	stopMotor(DriveLeft_2);
	stopMotor(DriveRight_1);
	stopMotor(DriveRight_2);
	wait(.5);
	// programming brake used to stop robot after quick jolt of speed and reduce drift
}
