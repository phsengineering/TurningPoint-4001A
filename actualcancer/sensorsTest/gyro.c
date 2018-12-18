#pragma config(Motor, port2, rightMotor, tmotorNormal, openLoop)
task main()
{
	SensorType[in8] = sensorNone;
	wait1Msec(1000);
	SensorType[in8] = sensorGyro;
	wait1Msec(2000);
	int startingPos = (SensorValue[in8]);
	wait(1);
	while(true)
	{
		if(abs(SensorValue[in8]-startingPos)>100)
		{
			motor[rightMotor]=63;
			wait(2);
			motor[rightMotor]=0;
		}
	}
}
//zoe dids it
