#pragma once
double acc_x(double angle, double acc_lr, double acc_fb);
double acc_y(double angle, double acc_lr, double acc_fb);

double velocityx(double acc_x, double time_acc_x,double vo, double thta_int);

double velocityy(double acc_y, double time_acc_y, double velocity_int, double theta_int);

double positionx(double startpos, double time_acc, double time_vel, double accx, double thta_int, double velocity_int);
double positiony(double startpos_y, double time_acc, double time_vel, double accy, double thta_int, double velocity_int);


void nextstuff(double nextint[]);
