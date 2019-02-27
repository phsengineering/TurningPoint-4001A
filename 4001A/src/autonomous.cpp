#include "main.h"
#include "subsystems.hpp"
#include <cmath>
int runningSpeed = 7;
void autonomous() {
  if(auton == 0) { //Red autonomous
    setIntake(100);
    setFlywheel(600);
    resetEncoders();
    while(frontLeft.get_position() < 1050) {
      if (frontLeft.get_position() < 150 && runningSpeed < 150) {   //acceleration
        //pow(runningSpeed, 2);
        runningSpeed*=3.5;  //acceleration multiplier
        autoDrive(runningSpeed);
        pros::delay(10);
      }
      if(frontLeft.get_position() > 150 && frontLeft.get_position() < 780) {
        runningSpeed = 150;
        autoDrive(runningSpeed);
      }
      if(frontLeft.get_position() > 780) {  //deceleration
        runningSpeed/=5;
        //sqrt(runningSpeed);
        autoDrive(runningSpeed);
        pros::delay(10);
      }
    }
    autoDrive(0);
    autoReset();
    pros::delay(1000);  //pause to intake ball
    runningSpeed = -7;
    while(frontLeft.get_position() > -1025) {
      /*
      if (frontLeft.get_position() > -150 && runningSpeed > -175) {
        runningSpeed*=4;  //acceleration multiplier
        autoDrive(runningSpeed);
        pros::delay(10);
      }
      if(frontLeft.get_position() < -150 && frontLeft.get_position() > -1100) {
        runningSpeed = -175;
        autoDrive(runningSpeed);
      }
      if(frontLeft.get_position() > -1100) {
        runningSpeed/=4;  //acceleration multiplier
        autoDrive(runningSpeed);
        pros::delay(10);
      }
      */
      autoDrive(-140);
    }
    autoDrive(0);
    autoReset();
    pros::delay(450);
    while(frontLeft.get_position() > -250 && frontRight.get_position() < 250) {
      frontRight.move_velocity(75);
      backRight.move_velocity(75);
      frontLeft.move_velocity(-75);
      backLeft.move_velocity(-75);
    }
    /*
    frontRight.move_absolute(250, 75); //90* counterclockwise turn  (263)
    backRight.move_absolute(250, 75);
    frontLeft.move_absolute(-252, -75);
    backLeft.move_absolute(-252, -75);
    */
    autoDrive(0);
    autoReset();

    while(frontLeft.get_position() < 205) { //moving forward to make the first shot
      autoDrive(75);
    }
    autoDrive(0);
    autoReset();
    pros::delay(100);
    setIndexer(127);
    pros::delay(300);
    setIndexer(0);
    resetEncoders();

    while(frontLeft.get_position() < 666) { //moving forward for second shot (725, or 650)
      autoDrive(75);
    }
    autoDrive(0);
    autoReset();
    setIndexer(127); //second shot
    setIntake(127);
    pros::delay(2000);
    setIndexer(0);
    setIntake(0);

    runningSpeed = -7;
    while(frontLeft.get_position() > -1500) {   //moving backwards to platform
      /*
      if (frontLeft.get_position() > -150 && runningSpeed > -175) {
        runningSpeed*=4;  //acceleration multiplier
        autoDrive(runningSpeed);
        pros::delay(10);
      }
      if(frontLeft.get_position() < -150 && frontLeft.get_position() > -700) {
        runningSpeed = -175;
        autoDrive(runningSpeed);
      }
      if(frontLeft.get_position() > -700) {
        runningSpeed/=4;  //acceleration multiplier
        autoDrive(runningSpeed);
        pros::delay(10);
      }
      */
      autoDrive(-160);
    }

    autoDrive(0);
    autoReset();
    pros::delay(100);
    while(frontLeft.get_position() < 255 && frontRight.get_position() > -255) { //clockwise turn to align
      frontRight.move_velocity(-75);
      backRight.move_velocity(-75);
      frontLeft.move_velocity(75);
      backLeft.move_velocity(75);
    }

    autoDrive(0);
    autoReset();
    pros::delay(450);
    while(frontLeft.get_position() < 1325) { //climb platform
      autoDrive(200);
    }
    autoDrive(0);
    autoReset();

}
else if(auton == 1) { //Blue autonomous
  setIntake(100);
  setFlywheel(600);
  resetEncoders();
  while(frontLeft.get_position() < 1050) {
    if (frontLeft.get_position() < 150 && runningSpeed < 150) {   //acceleration
      //pow(runningSpeed, 2);
      runningSpeed*=3.5;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() > 150 && frontLeft.get_position() < 780) {
      runningSpeed = 150;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > 780) {  //deceleration
      runningSpeed/=5;
      //sqrt(runningSpeed);
      autoDrive(runningSpeed);
      pros::delay(10);
    }
  }
  autoDrive(0);
  autoReset();
  pros::delay(1000);  //pause to intake ball
  runningSpeed = -7;
  while(frontLeft.get_position() > -1025) {
    /*
    if (frontLeft.get_position() > -150 && runningSpeed > -175) {
      runningSpeed*=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() < -150 && frontLeft.get_position() > -1100) {
      runningSpeed = -175;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > -1100) {
      runningSpeed/=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    */
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() < 245 && frontRight.get_position() > -245) {
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  /*
  frontRight.move_absolute(250, 75); //90* counterclockwise turn  (263)
  backRight.move_absolute(250, 75);
  frontLeft.move_absolute(-252, -75);
  backLeft.move_absolute(-252, -75);
  */
  autoDrive(0);
  autoReset();

  //while(frontLeft.get_position() < 45) { //moving forward to make the first shot
  //  autoDrive(75);
  //}
  autoDrive(0);
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 725) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(2000);
  setIndexer(0);
  setIntake(0);

  runningSpeed = -7;
  while(frontLeft.get_position() > -1375) {   //moving backwards to platform
    /*
    if (frontLeft.get_position() > -150 && runningSpeed > -175) {
      runningSpeed*=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() < -150 && frontLeft.get_position() > -700) {
      runningSpeed = -175;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > -700) {
      runningSpeed/=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    */
    autoDrive(-160);
  }

  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() > -250 && frontRight.get_position() < 250) {
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }

  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() < 1300) { //climb platform
    autoDrive(200);
  }
  autoDrive(0);
  autoReset();
}
else if(auton == 2) { //Back autonomous
  setIntake(100);
  resetEncoders();
  while(frontLeft.get_position() < 1050) {
    if (frontLeft.get_position() < 150 && runningSpeed < 150) {   //acceleration
      //pow(runningSpeed, 2);
      runningSpeed*=3.5;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() > 150 && frontLeft.get_position() < 780) {
      runningSpeed = 150;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > 780) {  //deceleration
      runningSpeed/=5;
      //sqrt(runningSpeed);
      autoDrive(runningSpeed);
      pros::delay(10);
    }
  }
  autoDrive(0);
  autoReset();
}
else if(auton == 3) { //Red low flag
  setIntake(100);
  setFlywheel(600);
  resetEncoders();
  while(frontLeft.get_position() < 1050) {
    if (frontLeft.get_position() < 150 && runningSpeed < 150) {   //acceleration
      //pow(runningSpeed, 2);
      runningSpeed*=3.5;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() > 150 && frontLeft.get_position() < 780) {
      runningSpeed = 150;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > 780) {  //deceleration
      runningSpeed/=5;
      //sqrt(runningSpeed);
      autoDrive(runningSpeed);
      pros::delay(10);
    }
  }
  autoDrive(0);
  autoReset();
  pros::delay(400);  //pause to intake ball
  runningSpeed = -7;
  while(frontLeft.get_position() > -1055) {
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() > -250 && frontRight.get_position() < 250) {
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }
  autoDrive(0);
  autoReset();
  while(frontLeft.get_position() < 225) { //moving forward for first shot
    autoDrive(75);
  }

  autoDrive(0);
  autoReset();
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 576) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(800);
  setIndexer(0);
  setIntake(0);
  while(frontRight.get_position() < 10 && frontLeft.get_position() > -10) { //turn for low flag
    frontLeft.move_velocity(-100);
    frontRight.move_velocity(100);
    backLeft.move_velocity(-100);
    backRight.move_velocity(100);

  }
  autoDrive(0);
  autoReset();
  autoDrive(150);
  pros::delay(700); //move forward to toggle flag and align with wall

  autoDrive(0);
  autoReset();

  setIntake(127);
  setIndexer(127); //index in for future cap flip
  pros::delay(400);
  setIndexer(0);
  setIntake(0);
  while(frontLeft.get_position() > -660) { //go back to align with cap
    autoDrive(-140);

  }
  autoDrive(0);
  autoReset();
  pros::delay(100);
  while(frontLeft.get_position() < 255 && frontRight.get_position() > -255) { //clockwise turn to align with cap
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();
  setIntake(-60);
  while(frontLeft.get_position() < 930) { //go ahead and hit cap
    autoDrive(120);
  }
  autoDrive(0);
  autoReset();

  while(frontLeft.get_position() > -80) { //pull back from cap
    autoDrive(-160);
  }
  autoDrive(0);
  autoReset();

  setFlywheel(0); //the flywheel, otherwise okeee it overheats the motors
  pros::delay(100);
  while(frontLeft.get_position() > -175 && frontRight.get_position() < 175) { //clockwise turn to align with cap
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }
  autoDrive(0);
  autoReset();
  pros::delay(100);
  while(frontLeft.get_position() < 900) {
    frontLeft.move_velocity(180);
    frontRight.move_velocity(200);
    backRight.move_velocity(200);
    backLeft.move_velocity(180);
  }
  autoDrive(0);
  resetEncoders();
  while(frontLeft.get_position() < 100) {
    frontRight.move_velocity(200);
    backRight.move_velocity(200);

  }
  autoDrive(0);
  autoReset();


}
else if(auton == 4) { //Blue low flag THIS NEEdS TO BE UPDATED.
  setIntake(100);
  setFlywheel(600);
  resetEncoders();
  while(frontLeft.get_position() < 1050) {
    if (frontLeft.get_position() < 150 && runningSpeed < 150) {   //acceleration
      //pow(runningSpeed, 2);
      runningSpeed*=3.5;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() > 150 && frontLeft.get_position() < 780) {
      runningSpeed = 150;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > 780) {  //deceleration
      runningSpeed/=5;
      //sqrt(runningSpeed);
      autoDrive(runningSpeed);
      pros::delay(10);
    }
  }
  autoDrive(0);
  autoReset();
  pros::delay(1000);  //pause to intake ball
  runningSpeed = -7;
  while(frontLeft.get_position() > -1025) {
    /*
    if (frontLeft.get_position() > -150 && runningSpeed > -175) {
      runningSpeed*=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() < -150 && frontLeft.get_position() > -1100) {
      runningSpeed = -175;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > -1100) {
      runningSpeed/=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    */
    autoDrive(-70);
  }
  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() < 265 && frontRight.get_position() > -265) {
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  /*
  frontRight.move_absolute(250, 75); //90* counterclockwise turn  (263)
  backRight.move_absolute(250, 75);
  frontLeft.move_absolute(-252, -75);
  backLeft.move_absolute(-252, -75);
  */
  autoDrive(0);
  autoReset();

  //while(frontLeft.get_position() < 45) { //moving forward to make the first shot
  //  autoDrive(75);
  //}
  autoDrive(0);
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 725) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(2000);
  setIndexer(0);
  setIntake(0);

  while(frontRight.get_position() > -15 && frontLeft.get_position() < 15) {
    frontLeft.move_velocity(100);
    frontRight.move_velocity(-100);
    backLeft.move_velocity(100);
    backRight.move_velocity(-100);

  }
  autoDrive(0);
  autoReset();
  while(frontLeft.get_position() < 666) {
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
}
else if(auton == 5) { //programming skills
  setIntake(100);
  setFlywheel(600);
  resetEncoders();
  while(frontLeft.get_position() < 1050) {
    if (frontLeft.get_position() < 150 && runningSpeed < 150) {   //acceleration
      //pow(runningSpeed, 2);
      runningSpeed*=3.5;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() > 150 && frontLeft.get_position() < 780) {
      runningSpeed = 150;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > 780) {  //deceleration
      runningSpeed/=5;
      //sqrt(runningSpeed);
      autoDrive(runningSpeed);
      pros::delay(10);
    }
  }
  autoDrive(0);
  autoReset();
  pros::delay(1000);  //pause to intake ball
  runningSpeed = -7;
  while(frontLeft.get_position() > -1025) {
    /*
    if (frontLeft.get_position() > -150 && runningSpeed > -175) {
      runningSpeed*=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() < -150 && frontLeft.get_position() > -1100) {
      runningSpeed = -175;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > -1100) {
      runningSpeed/=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    */
    autoDrive(-70);
  }
  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() > -255 && frontRight.get_position() < 255) {
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }
  /*
  frontRight.move_absolute(250, 75); //90* counterclockwise turn  (263)
  backRight.move_absolute(250, 75);
  frontLeft.move_absolute(-252, -75);
  backLeft.move_absolute(-252, -75);
  */
  autoDrive(0);
  autoReset();

  //while(frontLeft.get_position() < 45) { //moving forward to make the first shot
  //  autoDrive(75);
  //}
  autoDrive(0);
  pros::delay(100);
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 725) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(2000);
  setIndexer(0);
  setIntake(0);

  runningSpeed = -7;
  while(frontLeft.get_position() > -1400) {   //moving backwards to platform
    /*
    if (frontLeft.get_position() > -150 && runningSpeed > -175) {
      runningSpeed*=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    if(frontLeft.get_position() < -150 && frontLeft.get_position() > -700) {
      runningSpeed = -175;
      autoDrive(runningSpeed);
    }
    if(frontLeft.get_position() > -700) {
      runningSpeed/=4;  //acceleration multiplier
      autoDrive(runningSpeed);
      pros::delay(10);
    }
    */
    autoDrive(-160);
  }

  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() < 340 && frontRight.get_position() > -340) {
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }

  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() < 2350) { //climb platform
    autoDrive(200);
  }
  autoDrive(0);
  autoReset();
}
}


/*robot width = 12.25
  robot circumference = 38.4845
  ((1/8)(C))/(wheel circumference) = # of revolutions of wheel
  # of revolutions of wheel * 900 = 90* turn
  345 encoder ticks = 90* turn

void leftTurn() {
  frontRight.move_absolute(105, 50);
  backRight.move_absolute(105, 50);
  frontRight.move_absolute(-105, -50);
  frontRight.move_absolute(-105, -50);

}
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
  autoDrive(-1100, -200);
  while (!((((frontLeft.get_position() + frontRight.get_position())/2.0) > -1005) && (((frontLeft.get_position() + frontRight.get_position())/2.0) < -995))) {
    pros::delay(2);
  }

}
*/

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
