#include "position and movement.h"
#include <stdio.h>

int iterant(double velocity_initial, double theta_initial, double position_x_initial, double position_y_initial) {
	double velocity = velocity_initial;
	double theta_next = theta_initial;
	double position_x = position_x_initial;
	double position_y = position_y_initial;

	double inter[] = { velocity, theta_next, position_x, position_y };
	nextstuff(inter);


	int again = 1;
	printf("\tGo again? (0 if no, any other number if yes): ");
	scanf_s("%d", &again);


	if (again == 0) return 0;
	else {
		iterant(velocity, theta_next, position_x, position_y);
	}
}

	int main()  {

	double velocity_initial = 0;
	double theta_initial = 0;
	double position_x_initial = 0;
	double position_y_initial= 0;

	printf("\tInitial velocity? -> ");
	scanf_s("%lf", &velocity_initial);

	printf("\tAt what angle? (rad) -> ");
	scanf_s("%lf", &theta_initial);

	double deborg = iterant(velocity_initial, theta_initial, position_x_initial, 0);

	return deborg;
}
