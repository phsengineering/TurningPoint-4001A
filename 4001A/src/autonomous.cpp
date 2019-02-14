#include "main.h"
#include "subsystems.hpp"
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
void autonomous() {

    double forward = frontLeft.get_position() + frontRight.get_position();
    double backward = backLeft.get_position() + backLeft.get_position();
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


}
