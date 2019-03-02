#include "main.h"
#include "subsystems.hpp"
#include <cmath>
int runningSpeed = 7;

/*
while(frontLeft.get_position() < 273 && frontRight.get_position() > -273) {
  frontRight.move_velocity(-75);
  backRight.move_velocity(-75);          PERFEct 90 clockwise turn
  frontLeft.move_velocity(75);
  backLeft.move_velocity(75);
}
autoDrive(0);
autoReset();
-------------------------------------------------------------------------------
while(frontLeft.get_position() > -273 && frontRight.get_position() < 273) {
  frontRight.move_velocity(75);
  backRight.move_velocity(75);          PERFEct 90 clockwise turn
  frontLeft.move_velocity(-75);
  backLeft.move_velocity(-75);
}
autoDrive(0);
autoReset();
*/

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
    pros::delay(400);  //pause to intake ball
    runningSpeed = -7;
    while(frontLeft.get_position() > -1000) {
      autoDrive(-140);
    }
    autoDrive(0);
    autoReset();
    pros::delay(250);
    while(frontLeft.get_position() > -289 && frontRight.get_position() < 289) {
      frontRight.move_velocity(75);
      backRight.move_velocity(75);
      frontLeft.move_velocity(-75);
      backLeft.move_velocity(-75);
    }
    autoDrive(0);
    autoReset();
    pros::delay(250);
    while(frontLeft.get_position() < 135) { //moving forward for first shot
      autoDrive(75);
    }

    autoDrive(0);
    autoReset();
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
    pros::delay(800);
    setIndexer(0);
    pros::delay(1200);
    setIntake(0);
    while(frontRight.get_position() < 11 && frontLeft.get_position() > -11) { //turn for low flag
      frontLeft.move_velocity(-100);
      frontRight.move_velocity(100);
      backLeft.move_velocity(-100);
      backRight.move_velocity(100);

    }
    autoDrive(0);
    autoReset();
    autoDrive(150);
    pros::delay(720); //move forward to toggle flag and align with wall

    autoDrive(0);
    autoReset();

    setIntake(127);
    setIndexer(127); //index in for future cap flip
    pros::delay(300);
    setIndexer(0);
    setIntake(0);
    runningSpeed = -7;
    while(frontLeft.get_position() > -2000) {   //moving backwards to platform
    autoDrive(-160);
    }

    autoDrive(0);
    autoReset();
    pros::delay(100);

    while(frontLeft.get_position() < 300 && frontRight.get_position() > -300) { //clockwise turn to align
      frontRight.move_velocity(-75);
      backRight.move_velocity(-75);
      frontLeft.move_velocity(75);
      backLeft.move_velocity(75);
    }

    autoDrive(0);
    autoReset();
    pros::delay(450);

    while(frontLeft.get_position() < 1305) { //climb platform
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
  pros::delay(400);  //pause to intake ball
  runningSpeed = -7;
  while(frontLeft.get_position() > -1015) {
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();
  pros::delay(350);
  while(frontLeft.get_position() < 295 && frontRight.get_position() > -295) {
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();
  pros::delay(300);
  while(frontLeft.get_position() < 215) { //moving forward for first shot
    autoDrive(75);
  }

  autoDrive(0);
  autoReset();
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 630) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(800);
  setIndexer(0);
  pros::delay(1500);
  setIntake(0);
  while(frontRight.get_position() > -11 && frontLeft.get_position() < 11) { //turn for low flag
    frontLeft.move_velocity(100);
    frontRight.move_velocity(-100);
    backLeft.move_velocity(100);
    backRight.move_velocity(-100);

  }
  autoDrive(0);
  autoReset();
  autoDrive(150);
  pros::delay(800); //move forward to toggle flag and align with wall

  autoDrive(0);
  autoReset();

  setIntake(127);
  setIndexer(127); //index in for future cap flip
  pros::delay(300);
  setIndexer(0);
  setIntake(0);

  runningSpeed = -7;
  while(frontLeft.get_position() > -1924) {   //moving backwards to platform
    autoDrive(-160);
  }

  autoDrive(0);
  autoReset();
  pros::delay(100);
  while(frontLeft.get_position() > -300 && frontRight.get_position() < 300) { //clockwise turn to align
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }

  autoDrive(0);
  autoReset();
  pros::delay(450);
  while(frontLeft.get_position() < 1305) { //climb platform
    autoDrive(200);
  }
  autoDrive(0);
  autoReset();

}


else if(auton == 2) { //RED Back autonomous
  setIntake(100);
  setFlywheel(600);
  while(flywheel.get_actual_velocity() < 545) {
    pros::delay(10);
  }
  setIndexer(127);
  pros::delay(1000);
  setIndexer(0);
  setIntake(0);
  resetEncoders();
while(frontRight.get_position() > -240) {
    frontLeft.move_velocity(60);
    backLeft.move_velocity(60);
    backRight.move_velocity(-100);
    frontRight.move_velocity(-100);
  }

  autoDrive(0);
  autoReset();
  pros::delay(1000);
  setIntake(100);
  while(frontLeft.get_position() < 1150) {
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
  pros::delay(1500);
  while(frontLeft.get_position() > -200) {
    autoDrive(-150);
  }
  autoDrive(0);
  autoReset();
  while(frontLeft.get_position() < (0.75*255) && frontRight.get_position() > -(0.75*255)) {
    frontLeft.move_velocity(150);
    backLeft.move_velocity(150);
    frontRight.move_velocity(-150);
    backRight.move_velocity(-150);
  }
  autoDrive(0);
  autoReset();
  pros::delay(100);
  autoDrive(-150);
  pros::delay(1500);
  resetEncoders();
  while(frontLeft.get_position() < 1500) {
    autoDrive(150);
  }
  autoDrive(0);
  autoReset();
}


else if(auton == 3) { //Blue Back autonomous
  setFlywheel(600);
  while(flywheel.get_actual_velocity() < 530) {
    pros::delay(1000);
  }
  setIndexer(127);
  setIntake(127);
  pros::delay(1000);
  setIndexer(0);
  setIntake(0);
  resetEncoders();
while(frontRight.get_position() < 70) {
    frontLeft.move_velocity(-100);
    backLeft.move_velocity(-100);
    backRight.move_velocity(60);
    frontRight.move_velocity(60);
  }

  autoDrive(0);
  resetEncoders();
  pros::delay(1000);
  setIntake(100);
  while(frontLeft.get_position() < 1150) {
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
  pros::delay(1500);
  while(frontLeft.get_position() > -200) {
    autoDrive(-150);
  }
  autoDrive(0);
  autoReset();
  while(frontLeft.get_position() > -(0.72*255) && frontRight.get_position() < (0.72*255)) {
    frontLeft.move_velocity(-150);
    backLeft.move_velocity(-150);
    frontRight.move_velocity(150);
    backRight.move_velocity(150);
  }
  autoDrive(0);
  autoReset();
  pros::delay(100);
  autoDrive(-150);
  pros::delay(1800);
  resetEncoders();
  while(frontLeft.get_position() < 1350) {
    autoDrive(150);
  }
  autoDrive(0);
  autoReset();
}


else if(auton == 4) { //Red low flag
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
  while(frontLeft.get_position() > -1000) {
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();
  pros::delay(250);
  while(frontLeft.get_position() > -286 && frontRight.get_position() < 286) {
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }
  autoDrive(0);
  autoReset();
  pros::delay(250);
  while(frontLeft.get_position() < 215) { //moving forward for first shot
    autoDrive(75);
  }

  autoDrive(0);
  autoReset();
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 586) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(800);
  setIndexer(0);
  setIntake(0);
  while(frontRight.get_position() < 11 && frontLeft.get_position() > -11) { //turn for low flag
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


else if(auton == 5) { //Blue low flag THIS NEEdS TO BE UPDATED.
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
  while(frontLeft.get_position() > -995) {
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();
  pros::delay(350);
  while(frontLeft.get_position() < 295 && frontRight.get_position() > -295) {
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();
  pros::delay(300);
  while(frontLeft.get_position() < 215) { //moving forward for first shot
    autoDrive(75);
  }

  autoDrive(0);
  autoReset();
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 630) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(800);
  setIndexer(0);
  pros::delay(1500);
  setIntake(0);
  while(frontRight.get_position() > -12 && frontLeft.get_position() < 12) { //turn for low flag
    frontLeft.move_velocity(100);
    frontRight.move_velocity(-100);
    backLeft.move_velocity(100);
    backRight.move_velocity(-100);

  }
  autoDrive(0);
  autoReset();
  autoDrive(150);
  pros::delay(800); //move forward to toggle flag and align with wall

  autoDrive(0);
  autoReset();

  setIntake(127);
  setIndexer(127); //index in for future cap flip
  pros::delay(300);
  setIndexer(0);
  setIntake(0);

  autoDrive(0);
  autoReset();
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
  while(frontLeft.get_position() > -255 && frontRight.get_position() < 255) { //clockwise turn to align with cap
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }
  autoDrive(0);
  autoReset();
  setIntake(-55);
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
  while(frontLeft.get_position() < 175 && frontRight.get_position() > -175) { //clockwise turn to align with cap
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();
  pros::delay(100);
  while(frontLeft.get_position() < 900) {
    frontLeft.move_velocity(200);
    frontRight.move_velocity(140);
    backRight.move_velocity(140);
    backLeft.move_velocity(200);
  }
  autoDrive(0);
  resetEncoders();
  while(frontRight.get_position() < 100) {
    backLeft.move_velocity(200);
    frontLeft.move_velocity(200);

  }
  autoDrive(0);
  autoReset();
}


else if(auton == 6) { //programming skills
  setIntake(100);
  setFlywheel(600);
  resetEncoders();
  while(frontLeft.get_position() < 1050) {//move forward to get first ball under cap
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
  while(frontLeft.get_position() > -1015) { //move back
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();
  pros::delay(250);
  while(frontLeft.get_position() > -275 && frontRight.get_position() < 275) { //90* counterclockwise turn
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }
  autoDrive(0);
  autoReset();

  pros::delay(250);
  while(frontLeft.get_position() < 1500) { //ASL;KDFJASDF;LKAJSDF;LAKSDJFAS;LDKFJASDL;KFASF
    autoDrive(140);
  }

  autoDrive(0);
  autoReset();
  pros::delay(200);
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
  pros::delay(1200);
  setIntake(0);

  while(frontRight.get_position() < 11 && frontLeft.get_position() > -11) { //turn for low flag
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

  runningSpeed = -7;

    setIntake(127);
    setIndexer(80);
  pros::delay(1000);
  setIntake(0);
  setIndexer(0);
  intake.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  indexer.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  while(frontLeft.get_position() > -1360) { //ASDFASDFASDFmove back and align with cap
    autoDrive(-140);
  }
  autoDrive(0);
  autoReset();

  autoDrive(0);
  autoReset();
  pros::delay(250);
  while(frontLeft.get_position() < 273 && frontRight.get_position() > -273) { //ASDFSADFASDFASDFASF90* clockwise turn
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();
  pros::delay(250);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
  indexer.set_brake_mode(E_MOTOR_BRAKE_COAST);
  setIntake(127);
  runningSpeed = -7;
  while(frontLeft.get_position() < 1400) { //move forward towards cap
    autoDrive(140);
  }
  autoDrive(0);
  autoReset();

  pros::delay(400);
  while(frontLeft.get_position() > -252 && frontRight.get_position() < 252) { //ASDFASDFASDF90* counterclockwise turn
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }

  autoDrive(0);
  autoReset();
  while(frontLeft.get_position() < 215) { //moving forward for first shot
    autoDrive(75);
  }

  autoDrive(0);
  autoReset();
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 586) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();
  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(800);
  setIndexer(0);
  pros::delay(2200);
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

  while(frontLeft.get_position() > -660) { //go back next to cap
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
  setIntake(-60);  //intake reverse
  while(frontLeft.get_position() < 930) {   //move forward to flip cap
    autoDrive(120);
  }
  autoDrive(0);
  autoReset();

  //90* clockwise turn
  pros::delay(100);
  while(frontLeft.get_position() < 255 && frontRight.get_position() > -255) { //clockwise turn to align with cap
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }

  //intake off
  setIntake(0);

  //move forward 1 tile
  while(frontLeft.get_position() < 660) {
    autoDrive(140);

  }
  autoDrive(0);
  autoReset();

  //90* clockwise turn
  pros::delay(100);
  while(frontLeft.get_position() < 255 && frontRight.get_position() > -255) { //clockwise turn to align with cap
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();

  //intake on
  setIntake(127);

  //move forward
  while(frontLeft.get_position() < 660) { //go back next to cap
    autoDrive(140);
  }
  autoDrive(0);
  autoReset();

  //move back 1 tile
  while(frontLeft.get_position() > -660) {
    autoDrive(-140);

  }
  autoDrive(0);
  autoReset();

  //90* clockwise
  pros::delay(100);
  while(frontLeft.get_position() < 255 && frontRight.get_position() > -255) { //clockwise turn to align with cap
    frontRight.move_velocity(-75);
    backRight.move_velocity(-75);
    frontLeft.move_velocity(75);
    backLeft.move_velocity(75);
  }
  autoDrive(0);
  autoReset();

  //regular 3 shot pattern
  while(frontLeft.get_position() < 215) { //moving forward for first shot
    autoDrive(75);
  }

  autoDrive(0);
  autoReset();
  setIndexer(127);
  pros::delay(300);
  setIndexer(0);
  resetEncoders();

  while(frontLeft.get_position() < 586) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();

  setIndexer(127); //second shot
  setIntake(127);
  pros::delay(800);
  setIndexer(0);
  setIntake(0);

  while(frontRight.get_position() < 11 && frontLeft.get_position() > -11) { //turn for low flag
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

  //move back
  while(frontLeft.get_position() < 586) { //moving forward for second shot (725, or 650)
    autoDrive(75);
  }
  autoDrive(0);
  autoReset();

  //weird counterclockwise turn
  pros::delay(250);
  while(frontLeft.get_position() > -120 && frontRight.get_position() < 120) { //ASDFASDFASDF90* counterclockwise turn
    frontRight.move_velocity(75);
    backRight.move_velocity(75);
    frontLeft.move_velocity(-75);
    backLeft.move_velocity(-75);
  }

  autoDrive(0);
  autoReset();

  //go back to hit wall
  autoDrive(0);
  autoReset();
  pros::delay(100);
  autoDrive(-150);
  pros::delay(1500);
  resetEncoders();

    //go forward and platform
  while(frontLeft.get_position() < 1350) {
    autoDrive(150);
  }
  autoDrive(0);
  autoReset();


}

else if(auton == 7) {

}
}
