#include "subsystems.hpp"

//Drivetrain
Motor frontLeft(1, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor backLeft(2, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor frontRight(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor backRight(4, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

void drive(int y, int r)
{
    //Scale up y and r from 127 to 12000
    y *= 12000.0 / 127.0;
    r *= 12000.0 / 127.0;

    frontLeft.move_voltage(y + r);
    backLeft.move_voltage(y + r);
    frontRight.move_voltage(y - r);
    backRight.move_voltage(y - r);
}

//Lift
Motor liftMotor(8, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);

void setLift(int speed)
{
    liftMotor.move_velocity(speed);
}

//Flywheel
Motor flywheel(7, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
void setFlywheel(int velocity)
{
    flywheel.move_velocity(velocity);
}

Motor indexer(5, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
void setIndexer(int speed)
{
    indexer.move_voltage(speed * 12000.0 / 127.0);
}
Motor intake(6, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
void setIntake(int speed)
{
    intake.move_voltage(speed * 12000.0 / 127.0);
}