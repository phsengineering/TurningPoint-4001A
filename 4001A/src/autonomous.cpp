#include "main.h"
#include "subsystems.hpp"

void autonomous() {

  setFlywheel(600);
  setIntake(127);
  autoDrive(1000, 200); // Moves 100 units forward


  while (!((((frontLeft.get_position() + frontRight.get_position())/2.0) < 1005) && (((frontLeft.get_position() + frontRight.get_position())/2.0) > 995))) {
  // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
  }
  autoReset();
  pros::delay(100);
  autoDrive(-1000, -200);
  while (!((((frontLeft.get_position() + frontRight.get_position())/2.0) > -1005) && (((frontLeft.get_position() + frontRight.get_position())/2.0) < -995))) {
    pros::delay(2);
  }

}


/*
#include "main.h"
#include "okapi/api.hpp"
//#include "subsystems.hpp"
using namespace okapi; //import new okapi library

const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 16_in;
const double liftkP = 0.001; //i am not 100% what these do
const double liftkI = 0.0001;
const double liftkD = 0.0001;
//Motor intake(6, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
auto chassis = ChassisControllerFactory::create(
  {-1, -2}, {3, 4},
  AbstractMotor::gearset::green,
  {WHEEL_DIAMETER, CHASSIS_WIDTH}
); //create PID objects
auto liftController = AsyncControllerFactory::posPID(8, liftkP, liftkI, liftkD);
//auto liftController = AsyncControllerFactory::posPID(8, liftkP, liftkI, liftkD);
pros::Motor flywheel_auton (7);
pros::Motor intake_auton (6);
pros::Motor indexer_auton (5);

void autonomous() {
  intake_auton.move_voltage(12000);
  flywheel_auton.move_velocity(600);
  chassis.setMaxVelocity(150);
  chassis.moveDistance(1000); // Move 1000 motor degrees forward
  chassis.waitUntilSettled(); //could this be the programming brake they speak of?

  pros::Task::delay(1000);

  chassis.moveDistance(-1100);
  chassis.waitUntilSettled();
  pros::Task::delay(500);
  chassis.setMaxVelocity(70);
  chassis.turnAngle(-66_deg);
  chassis.waitUntilSettled();

  pros::Task::delay(500);
  indexer_auton.move_voltage(127.0 * 12000.0 / 127.0);
  pros::Task::delay(600);
  indexer_auton.move_voltage(0);

  chassis.waitUntilSettled();
  chassis.moveDistance(800);
  chassis.waitUntilSettled();
  indexer_auton.move_voltage(127.0 * 12000.0 / 127.0);
  pros::Task::delay(1500);
  indexer_auton.move_voltage(0);
  intake_auton.move_voltage(0);
  flywheel_auton.move_velocity(0);
  chassis.setMaxVelocity(200);
  chassis.moveDistance(-1500);
  chassis.waitUntilSettled();
  chassis.turnAngle(90);
  chassis.waitUntilSettled();
  chassis.moveDistance(2000);
  chassis.waitUntilSettled();
}
*/
