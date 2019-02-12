#include "main.h"
#include "subsystems.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

pros::Controller mainController = Controller(E_CONTROLLER_MASTER);
pros::Controller partnerController = Controller(E_CONTROLLER_PARTNER);
void opcontrol() {
	while(true) {
		//Drive
		int y = mainController.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int r = mainController.get_analog(E_CONTROLLER_ANALOG_LEFT_X);

		//Make r half as sensitive if not going forward or backward
		if(std::abs(y) < 16)
		{
			r = 127.0 * std::copysign(std::pow(std::abs(r / 127.0), 1.8), r);
		}

		drive(y, r);

		//Lift
		if(mainController.get_digital(E_CONTROLLER_DIGITAL_L1))
		{
			liftMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    		setLift(0);
		}
		else
		{
			liftMotor.set_brake_mode(E_MOTOR_BRAKE_COAST);
			setLift(mainController.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));	
		}

		//Flywheel
		if(partnerController.get_digital(E_CONTROLLER_DIGITAL_R1))
		{
			setFlywheel(600);
		}
		else
		{
			setFlywheel(0);
		}
		
		//Intake
		if(partnerController.get_digital(E_CONTROLLER_DIGITAL_R2))
		{
			setIntake(64);
		}
		else if(partnerController.get_digital(E_CONTROLLER_DIGITAL_X))
		{
			setIntake(-127);
		}
		else
		{
			setIntake(0);
		}

		//Indexer
		if(partnerController.get_digital(E_CONTROLLER_DIGITAL_L1))
		{
			setIndexer(127);
		}
		else if(partnerController.get_digital(E_CONTROLLER_DIGITAL_L2))
		{
			setIndexer(-127);
		}
		else
		{
			setIndexer(0);
		}
		
		
		

		pros::delay(20);
	}
}
