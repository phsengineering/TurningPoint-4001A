#pragma config(Sensor, in2,    accMetrics,     sensorAccelerometer)
#pragma config(Sensor, in3,    gyroMetrics,    sensorGyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() {
	float gyro;
	float vx;
	float vo_x;
	float acc_fb;
	float acc_lr;
	float acc_x;
	while(true) {
		
		 gyro = (SensorValue[gyroMetrics]/360); //get gyroMetrics in 
		 acc_fb = (SensorValue[accMetrics]);
		 acc_lr = (SensorValue[accMetrics]);
		 //calculate acc in x
	   acc_x = acc_fb * cosDegrees(gyro);
	   acc_x = acc_x + acc_lr * sinDegrees(gyro);
	   //calculate acc in y
	   acc_y = acc_fb * sinDegrees(gyro);
	   acc_y = acc_y + acc_lr * cosDegrees(gyro);
	   if(acc
		 vo_x = velocity_int * cosDegrees(thta_int);
	
	
		 vx = acc_x * time1[T1] + vo_x;
	}
}



float velocityx(float acc_x, float time_acc_x, float velocity_int, float thta_int)
{
	
	return vx;
}

float velocityy(float acc_y, float time_acc_y, float velocity_int, float theta_int)
{

	float vo_y;
	vo_y = velocity_int * sinDegrees(theta_int);

	float vy;
	vy = acc_y * time_acc_y+vo_y;
	return vy;
}

float positionx(float startpos_x, float time_acc, float time_vel, float accx, float thta_int, float velocity_int)
{
	float vo_x;
	vo_x = velocity_int * cosDegrees(thta_int);

	float disx_acc; //displacement directly after acceleration
	disx_acc = startpos_x + vo_x * time_acc + 0.5 * accx * time_acc * time_acc;


	float vf_x;
	vf_x = accx * time_acc + vo_x;

	float disx_total; //displacement directly after velocity
	disx_total = vf_x * time_vel + disx_acc;
	
	return disx_total;
}


float positiony(float startpos_x, float time_acc, float time_vel, float accx, float thta_int, float velocity_int)
{
	float vo_x;
	vo_x = velocity_int * sinDegrees(thta_int);

	float disx_acc; //displacement directly after acceleration
	disx_acc = startpos_x + vo_x * time_acc + 0.5 * accx * time_acc * time_acc;


	float vf_x;
	vf_x = accx * time_acc + vo_x;

	float disx_total; //displacement directly after velocity
	disx_total = vf_x * time_vel + disx_acc;

	return disx_total;
}
/*
float positiony(float startpos_y, float time_acc, float time_vel, float accy, float thta_int, float velocity_int)
{
	float vo_y;
	vo_y = velocity_int * sin(thta_int);

	float disy_acc; //displacement directly after acceleration
	disy_acc = startpos_y + vo_y * time_acc + 0.5 * accy * time_acc * time_acc;


	float vf_y;
	vf_y = accy * time_acc + vo_y;

	float disy_total; //displacement directly after velocity
	disy_total = vf_y * time_vel + disy_acc;

	return disy_total;
}
*/