#include "position and movement.h"
#include <stdio.h>
#include <math.h>

void nextstuff(double nextint[])
{
	double theta=0;
	double acc_fb_int=0;
	double acc_lr_int=0;
	double theo_time_acc=0;
	double theo_time_vel=0;
	double accx=0;   //acceleration east west
	double accy=0;   //acceleration north south
	double velocity_x=0;
	double velocity_y=0;
	double end_velocity=0;
	double velocity_int = nextint[0];
	double theta_int = nextint[1];
	double position_x = nextint[2];
	double position_y = nextint[3];


	printf("\tangle of new acceleration?: ");
	scanf_s("%lf", &theta);
	printf("\tinput acceleration from the back to the front: ");
	scanf_s("%lf", &acc_fb_int);
	printf("\tinput acceleration from the left to right: ");
	scanf_s("%lf", &acc_lr_int);
	printf("\thow long will it be accelerating? ");
	scanf_s("%lf", &theo_time_acc);
	printf("\thow long will it be moving after accelerating? ");
	scanf_s("%lf", &theo_time_vel);


	accx = acc_x(theta, acc_lr_int, acc_fb_int);
	accy = acc_y(theta, acc_lr_int, acc_fb_int);
	velocity_x = velocityx(accx, theo_time_acc, velocity_int, theta_int);
	velocity_y = velocityy(accy, theo_time_acc, velocity_int, theta_int);
	position_x = positionx(position_x, theo_time_acc, theo_time_vel, accx, theta_int, velocity_int);
	position_y = positiony(position_y, theo_time_acc, theo_time_vel, accy, theta_int, velocity_int);
	end_velocity = tan(velocity_y / velocity_x);

	printf("\tthe intitial acceleration in the x is: %f \n", (double) accx);
	printf("\tthe intitial acceleration in the y is: %f \n", (double) accy);
	printf("\tthe new velocity in the x is: %f \n", (double) velocity_x);
	printf("\tthe new velocity in the y is: %f \n", (double) velocity_y);
	printf("\tthe new total velocity is: %f \n", (double) end_velocity);
	printf("\tthe new position in the x is: %f \n", (double) position_x);
	printf("\tthe new position in the y is: %f \n", (double) position_y);

	nextint[0] = end_velocity;
	nextint[1] = theta;
	nextint[2] = position_x;
	nextint[3] = position_y;
}