#include "main.h"
#include "subsystems.hpp"
#include <sstream>
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 //RUN VERY CAREFULLY. BE READY TO INTERRUPT PROGRAM. POSSIBLE ISSUES INCLUDE BRAKES NOT AUTOMATICALLY
 //SHUTTING DOWN MOTORS
void autonomous() {
    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
    double forward = frontLeft.get_position() + frontRight.get_position();
    double backward = backLeft.get_position() + backLeft.get_position();
    std::ostringstream sstream;
		sstream << backRight.get_position();
		std::string brString = sstream.str();

		sstream << frontLeft.get_position();
		std::string flString = sstream.str();

		sstream << frontRight.get_position();
		std::string frString = sstream.str();

		sstream << backLeft.get_position();
		std::string blString = sstream.str();
    pros::lcd::set_text(0, "Back Right "  + brString);
		pros::lcd::set_text(1, "Back left " + blString);
		pros::lcd::set_text(2, "Front Left " + flString);
		pros::lcd::set_text(3, "Front Right " + frString);
    /*
    double firstLimit = 1000.0;
    while(forward < firstLimit) {
        frontLeft.move_voltage(12000);
        frontRight.move_voltage(12000);
        backLeft.move_voltage(12000);
        backRight.move_voltage(12000);

    }
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    pros::Task::delay(1000);
    */

		setFlywheel(600);
		while(frontLeft.get_position() < 1100) {
      frontLeft.move_voltage(12000);
      frontRight.move_voltage(12000);
      backLeft.move_voltage(12000);
      backRight.move_voltage(12000);
			setIntake(64);
		}
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
		pros::Task::delay(100);
		setIntake(64);
		pros::Task::delay(150);
    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_COAST);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_COAST);
    backRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
		while(frontLeft.get_position() > -1055)
		{
      frontLeft.move_voltage(-12000);
      frontRight.move_voltage(-12000);
      backLeft.move_voltage(-12000);
      backRight.move_voltage(-12000);
		}
		setFlywheel(600);

		pros::Task::delay(150);
    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
		//TURN CODE GOES HERE I DON'T KNOW HOW TO PROGRAM THIS REMOTELY
		pros::Task::delay(1000);

    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
		while(frontLeft.get_position() < 145)
		{
      frontLeft.move_voltage(6000);
      frontRight.move_voltage(6000);
      backLeft.move_voltage(6000);
      backRight.move_voltage(6000);
		}
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
		setIndexer(127);
		pros::Task::delay(1000);
		setIndexer(0);

    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_COAST);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_COAST);
    backRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
		while(frontLeft.get_position() < 325) {
      frontLeft.move_voltage(6000);
      frontRight.move_voltage(6000);
      backLeft.move_voltage(6000);
      backRight.move_voltage(6000);
		}
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
		setIndexer(127);
		pros::Task::delay(750);
		setIntake(127);
		pros::Task::delay(900);
		setIntake(0);
		setIndexer(0);
    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
		while(frontLeft.get_position() > -1500) {
      frontLeft.move_voltage(-12000);
      frontRight.move_voltage(-12000);
      backLeft.move_voltage(-12000);
      backRight.move_voltage(-12000);
		}
    frontLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    frontLeft.tare_position();
    backLeft.tare_position();
    frontRight.tare_position();
    backRight.tare_position();
    //PROGRAM THIS TURN AND THE FINAL PLATFORM MOUNT


}
