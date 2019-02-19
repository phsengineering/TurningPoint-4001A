#include "main.h"
#include "okapi/api.hpp"
//#include "subsystems.cpp" DO NOT IMPORT. 
using namespace okapi; //import new okapi library

const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 16_in;
const double liftkP = 0.001; //i am not 100% what these do
const double liftkI = 0.0001;
const double liftkD = 0.0001;
auto chassis = ChassisControllerFactory::create(
  {-1, -2}, {3, 4}
); //create PID objects
auto liftController = AsyncControllerFactory::posPID(8, liftkP, liftkI, liftkD);


void autonomous() {
  chassis.moveDistanceAsync(1000); // Move 1000 motor degrees forward
  chassis.waitUntilSettled(); //could this be the programming brake they speak of?

  chassis.moveDistanceAsync(0);
  liftController.setTarget(200); // Move lift motor 200 motor degrees upward
  chassis.waitUntilSettled();
  liftController.waitUntilSettled();
}
