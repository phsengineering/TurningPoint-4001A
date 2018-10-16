#include <math.h>

double acc_x(double angle, double acc_lr, double acc_fb)
{
	double acc_x;
	acc_x = acc_fb * cos(angle);
	acc_x = acc_x + acc_lr * sin(angle);
	return acc_x;
}

double acc_y(double angle, double acc_lr, double acc_fb)
{
	double acc_x;
	acc_x = acc_fb * sin(angle);
	acc_x = acc_x + acc_lr * cos(angle);
	return acc_x;
}

double velocityx(double acc_x, double time_acc_x, double velocity_int, double thta_int)
{
	double vo_x;
	vo_x = velocity_int * cos(thta_int);
	
	double vx;
	vx = acc_x * time_acc_x + vo_x;
	return vx;
}

double velocityy(double acc_y, double time_acc_y, double velocity_int, double theta_int)
{

	double vo_y;
	vo_y = velocity_int * sin(theta_int);

	double vy;
	vy = acc_y * time_acc_y+vo_y;
	return vy;
}

double positionx(double startpos_x, double time_acc, double time_vel, double accx, double thta_int, double velocity_int)
{
	double vo_x;
	vo_x = velocity_int * cos(thta_int);

	double disx_acc; //displacement directly after acceleration
	disx_acc = startpos_x + vo_x * time_acc + 0.5 * accx * time_acc * time_acc;


	double vf_x;
	vf_x = accx * time_acc + vo_x;

	double disx_total; //displacement directly after velocity
	disx_total = vf_x * time_vel + disx_acc;
	
	return disx_total;
}


double positiony(double startpos_x, double time_acc, double time_vel, double accx, double thta_int, double velocity_int)
{
	double vo_x;
	vo_x = velocity_int * sin(thta_int);

	double disx_acc; //displacement directly after acceleration
	disx_acc = startpos_x + vo_x * time_acc + 0.5 * accx * time_acc * time_acc;


	double vf_x;
	vf_x = accx * time_acc + vo_x;

	double disx_total; //displacement directly after velocity
	disx_total = vf_x * time_vel + disx_acc;

	return disx_total;
}
/*
double positiony(double startpos_y, double time_acc, double time_vel, double accy, double thta_int, double velocity_int)
{
	double vo_y;
	vo_y = velocity_int * sin(thta_int);

	double disy_acc; //displacement directly after acceleration
	disy_acc = startpos_y + vo_y * time_acc + 0.5 * accy * time_acc * time_acc;


	double vf_y;
	vf_y = accy * time_acc + vo_y;

	double disy_total; //displacement directly after velocity
	disy_total = vf_y * time_vel + disy_acc;

	return disy_total;
}
*/