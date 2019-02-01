#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in8,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl3,  descorerLimit,  sensorTouch)
#pragma config(Sensor, I2C_1,  rightQuad,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftQuad,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           DriveLeft_1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           DriveLeft_2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           DriveRight_1,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           DriveRight_2,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           indexer,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontRoller,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           descorer,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           flywheel,      tmotorVex393_MC29, openLoop)
#pragma config(Sensor, in1,    xAxis,               sensorAccelerometer)
#pragma config(Sensor, in2,    yAxis,               sensorAccelerometer)
#pragma config(Sensor, in3,    zAxis,               sensorAccelerometer)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify
#pragma platform(VEX2)
static int count = 0;
float accelRatio = 0;
float yPos = 0;
float yVel = 0;
float yAccel = 0;
float posAt1MSec = 0;
float errorFactor = 1.1667;

int zYDif = 0;
int originalY = 0;
void move(int uniformSpeed) {
    motor[DriveLeft_1] = uniformSpeed;
    motor[DriveLeft_2] = uniformSpeed;
    motor[DriveRight_1] = uniformSpeed;
    motor[DriveRight_2] = uniformSpeed;
}
task yPosition(){
  while(true){
    wait1Msec(1);//1 millisecond sampling time
    yAccel = (abs(SensorValue[yAxis] - originalY)) > 2 ? (SensorValue[yAxis] - originalY) / accelRatio : 0;
    //check if threshold is passed and set "instantanious" acceleration   
    yVel += (yAccel / 1000);//update "instantainious" velocity
    yPos += (yVel / 1000);//update position
  }
}
void turnHandler(const string operator, int gyroLimit, int rightSpeed, int leftSpeed, int brakeRight, int brakeLeft, int brakeTime) {
    if(strcmp(operator, ">") == 0) {
        while((SensorValue[in8]) > gyroLimit)
        {
            motor[DriveRight_1] = rightSpeed;
            motor[DriveRight_2] = rightSpeed;
            motor[DriveLeft_1] = leftSpeed;
            motor[DriveLeft_2] = leftSpeed;
        }
        motor[DriveRight_1] = brakeRight;
        motor[DriveRight_2] = brakeRight;
        motor[DriveLeft_1] = brakeLeft;
        motor[DriveLeft_2] = brakeLeft;
        wait1Msec(brakeTime);
    }
    if(strcmp(operator, ">") == 0) {
        while((SensorValue[in8]) > gyroLimit)
        {
            motor[DriveRight_1] = rightSpeed;
            motor[DriveRight_2] = rightSpeed;
            motor[DriveLeft_1] = leftSpeed;
            motor[DriveLeft_2] = leftSpeed;
        }
        motor[DriveRight_1] = brakeRight;
        motor[DriveRight_2] = brakeRight;
        motor[DriveLeft_1] = brakeLeft;
        motor[DriveLeft_2] = brakeLeft;
        wait1Msec(brakeTime);
    }

}
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;


void waitForPress()
{
    while(nLCDButtons == 0) {}
    wait1Msec(5);
}
void waitForRelease()
{
    while(nLCDButtons != 0) {}
    wait1Msec(5);
}
void pre_auton()
{
    //Declare count variable to keep track of our choice

    //------------- Beginning of User Interface Code ---------------
    //Clear LCD
    clearLCDLine(0);
    clearLCDLine(1);
    //Loop while center button is not pressed
    while(nLCDButtons != centerButton)
    {
        //Switch case that allows the user to choose from 4 different options
        switch(count) {
        case 0:
            //Display first choice
            displayLCDCenteredString(0, "Red front");
            displayLCDCenteredString(1, "<         Enter        >");
            waitForPress();
            //Increment or decrement "count" based on button press
            if(nLCDButtons == leftButton)
            {
                waitForRelease();
                count = 3;
            }
            else if(nLCDButtons == rightButton)
            {
                waitForRelease();
                count++;
            }
            break;
        case 1:
            //Display second choice
            displayLCDCenteredString(0, "Red back");
            displayLCDCenteredString(1, "<         Enter        >");
            waitForPress();
            //Increment or decrement "count" based on button press
            if(nLCDButtons == leftButton)
            {
                waitForRelease();
                count--;
            }
            else if(nLCDButtons == rightButton)
            {
                waitForRelease();
                count++;
            }
            break;
        case 2:
            //Display third choice
            displayLCDCenteredString(0, "Blue Front");
            displayLCDCenteredString(1, "<         Enter        >");
            waitForPress();
            //Increment or decrement "count" based on button press
            if(nLCDButtons == leftButton)
            {
                waitForRelease();
                count--;
            }
            else if(nLCDButtons == rightButton)
            {
                waitForRelease();
                count++;
            }
            break;
        case 3:
            //Display fourth choice
            displayLCDCenteredString(0, "Blue back");
            displayLCDCenteredString(1, "<         Enter        >");
            waitForPress();
            //Increment or decrement "count" based on button press
            if(nLCDButtons == leftButton)
            {
                waitForRelease();
                count--;
            }
            else if(nLCDButtons == rightButton)
            {
                waitForRelease();
                count = 0;
            }
            break;
        default:
            count = 0;
            break;
        }
    }
}

task autonomous() {
    clearLCDLine(0);
    clearLCDLine(1);
    {
        switch(count) {
        case 0:
            //If count = 0, run the code correspoinding with choice 1
            displayLCDCenteredString(0, "Red front");
            displayLCDCenteredString(1, "is running!");
            SensorValue[leftQuad] = 0;
            motor[flywheel] = -127;
            while(SensorValue[leftQuad] < 1100) {
                move(100);
                motor[frontRoller] = 127;
            }
            move(0);
            wait(.1);
            move(-127);
            wait(.15);
            move(0);
            motor[frontRoller] = 127;
            wait(.15);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] > -1055)
            {
                move(-63);
            }
            motor[flywheel] = -127;
            move(100);
            wait(.1);
            move(0);
            wait(.15);
            SensorValue[leftQuad]=0;
            SensorValue[gyro] = 0;
            turnHandler("<", 900, -60, 60, 60, -60, 125);
            move(0);
            wait(1.75);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] < 145)
            {
                move(60);
            }
            move(0);
            wait(.75);
            motor[indexer] = 127;
            wait(1);
            motor[indexer] = 0;

            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] < 325) {   //middle flag
                move(60);
            }
            move(0);
            motor[indexer] = 127;
            wait(.75);
            motor[frontRoller] = 127;
            wait(0.9);
            motor[frontRoller] = 0;
            motor[indexer] = 0;
            move(0);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] > -1555) {
                move(-127);
            }
            move(0);
            wait(.2);
            move(127);
            wait(.15);
            move(0);
            wait(.25);
            SensorValue[leftQuad] = 0;
            SensorValue[gyro] = 0;
            turnHandler(">", -900, 60, -60, -60, 60, 139);
            move(0);

            move(-127);
            wait(0.75);
            move(127);
            wait(2);
            move(0);
            break;
        case 1:
            displayLCDCenteredString(0, "Red back");
            displayLCDCenteredString(1, "is running!");
            SensorValue[leftQuad] = 0;
            motor[flywheel] = -127;
            while(SensorValue[leftQuad] < 1100) {
                move(100);
                motor[frontRoller] = 127;
            }
            move(0);
            wait(.1);
            move(-127);
            wait(.15);
            move(0);
            motor[frontRoller] = 127;
            wait(.25);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] > -1055)
            {
                move(-63);
            }
            motor[flywheel] = -127;
            move(100);
            wait(.1);
            move(0);
            wait(.15);
            SensorValue[leftQuad]=0;
            SensorValue[gyro] = 0;
            turnHandler("<", 900, -60, 60, 50, -50, 120);
            move(0);
            wait(1);

            SensorValue[leftQuad] = 0;

            while(SensorValue[leftQuad] < 810) {
                move(60);
            }
            move(-60);
            wait(.25);
            move(0);
            motor[frontRoller] = 127;
            motor[indexer] = 127;
            wait(3);
            motor[frontRoller] = 0;
            motor[indexer] = 0;
            SensorValue[leftQuad] = 0;
            SensorValue[gyro] = 0;
            turnHandler(">", -900, 60, -60, -60, 60, 134);
            move(0);
            wait(.5);
            move(-127);
            wait(.5);
            move(0);
            wait(.1);
            move(127);
            wait(2);
            move(0);
            motor[flywheel] = 0;
            break;
        case 2:
            displayLCDCenteredString(0, "Blue front");
            displayLCDCenteredString(1, "is running!");
            SensorValue[leftQuad] = 0;
            motor[flywheel] = -127;
            while(SensorValue[leftQuad] < 1100) {
                move(100);
                motor[frontRoller] = 127;
            }
            move(0);
            wait(.1);
            move(-127);
            wait(.15);
            move(0);
            motor[frontRoller] = 127;
            wait(.25);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] > -1055)
            {
                move(-63);
            }
            motor[flywheel] = -127;
            move(100);
            wait(.1);
            move(0);
            wait(.15);
            SensorValue[leftQuad]=0;
            SensorValue[gyro] = 0;
            turnHandler(">", -900, 60, -60, -60, 60, 120);
            move(0);
            wait(1.75);

            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] < 145)
            {
                move(60);
            }
            move(0);
            wait(.75);
            motor[indexer] = 127;
            wait(1);
            motor[indexer] = 0;
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] < 325) {   //middle flag
                move(60);
            }
            move(0);
            motor[indexer] = 127;
            wait(.75);
            motor[frontRoller] = 127;
            wait(0.9);
            motor[frontRoller] = 0;
            motor[indexer] = 0;
            move(0);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] > -1555) {
                move(-127);
            }
            move(0);
            wait(.2);
            move(127);
            wait(.15);
            move(0);
            wait(.25);
            SensorValue[leftQuad] = 0;
            SensorValue[gyro] = 0;
            turnHandler("<", 900, -60, 60, 60, -60, 139);
            move(0);
            move(-127);
            wait(0.75);
            move(127);
            wait(2);
            move(0);
            break;
        case 3:
            displayLCDCenteredString(0, "Blue back");
            displayLCDCenteredString(1, "is running!");
            SensorValue[leftQuad] = 0;
            motor[flywheel] = -127;
            while(SensorValue[leftQuad] < 1100) {
                move(100);
                motor[frontRoller] = 127;
            }
            move(0);
            wait(.1);
            move(-127);
            wait(.15);
            move(0);
            motor[frontRoller] = 127;
            wait(.25);
            SensorValue[leftQuad] = 0;
            while(SensorValue[leftQuad] > -1055)
            {
                move(-63);
            }
            motor[flywheel] = -100;
            move(100);
            wait(.1);
            move(0);
            wait(.15);
            SensorValue[leftQuad]=0;
            SensorValue[gyro] = 0;
            turnHandler(">", -920, 60, -60, -50, 50, 120);
            move(0);
            wait(1);

            SensorValue[leftQuad] = 0;

            while(SensorValue[leftQuad] < 740) {
                move(60);
            }
            move(-60);
            wait(.2);
            move(0);
            //motor[frontRoller] = 127;
            motor[indexer] = 127;
            wait(3);
            motor[indexer] = 0;
            motor[frontRoller] = 0;
            motor[flywheel] = 0;
            motor[indexer] = 0;
            SensorValue[leftQuad] = 0;
            SensorValue[gyro] = 0;
            turnHandler("<", 900, -60, 60, 60, -60, 128);
            move(0);
            wait(.5);
            SensorValue[leftQuad] = 0;
            SensorValue[gyro] = 0;
            while(SensorValue[leftQuad] < 900) {
                move(127);
            }
            move(0);
            break;
        case 4:
            displayLCDCenteredString(0, "BlueCF");
            displayLCDCenteredString(1, "is running!");
            break;
        default:
            displayLCDCenteredString(0, "No Auton");
            displayLCDCenteredString(1, "Selected");
            break;
        }
    }
}
#define     JOY_DRIVE_V     vexJSLeftV
#define     JOY_DRIVE_H     vexJSLeftH
#define     JOY_THRESHOLD   15


#define MOTOR_NUM               kNumbOfTotalMotors
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 9      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    250     // essentially off
#define MOTOR_TASK_DELAY        10      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          9

// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ];

// Array to hold "slew rate" for the motors, the maximum change every time the task
// runs checking current motor speed.
int motorSlew[ MOTOR_NUM ];
task MotorSlewRateTask()
{
    int motorIndex;
    int motorTmp;

    // Initialize stuff
    for(motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++)
    {
        motorReq[motorIndex] = 0;
        motorSlew[motorIndex] = MOTOR_DEFAULT_SLEW_RATE;
    }

    // run task until stopped
    while( true )
    {
        // run loop for every motor
        for( motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++)
        {
            // So we don't keep accessing the internal storage
            motorTmp = motor[ motorIndex ];

            // Do we need to change the motor value ?
            if( motorTmp != motorReq[motorIndex] )
            {
                // increasing motor value
                if( motorReq[motorIndex] > motorTmp )
                {
                    motorTmp += motorSlew[motorIndex];
                    // limit
                    if( motorTmp > motorReq[motorIndex] )
                        motorTmp = motorReq[motorIndex];
                }

                // decreasing motor value
                if( motorReq[motorIndex] < motorTmp )
                {
                    motorTmp -= motorSlew[motorIndex];
                    // limit
                    if( motorTmp < motorReq[motorIndex] )
                        motorTmp = motorReq[motorIndex];
                }

                // finally set motor
                motor[motorIndex] = motorTmp;
            }
        }

        // Wait approx the speed of motor update over the spi bus
        wait1Msec( MOTOR_TASK_DELAY );
    }
}


void
DriveLeftMotor( int value )
{
    motorReq[ DriveLeft_1 ] = value;
    motorReq[ DriveLeft_2 ] = value;
}


void
DriveRightMotor( int value )
{
    motorReq[ DriveRight_1 ] = value;
    motorReq[ DriveRight_2 ] = value;
}


task ArcadeDrive()
{
    int    ctl_v;
    int    ctl_h;
    int    drive_l;
    int    drive_r;

    // Basic arcade control
    while( true )
    {
        // Get joystick H and V control
        ctl_v = vexRT[ JOY_DRIVE_V ];
        ctl_h = -vexRT[ JOY_DRIVE_H ];

        // Ignore joystick near center
        if( (abs(ctl_v) <= JOY_THRESHOLD) && (abs(ctl_h) <= JOY_THRESHOLD) )
        {
            drive_l = 0;
            drive_r = 0;
        }
        else
        {
            // Create drive for left and right motors
            drive_l = (ctl_v + ctl_h) / 2;
            drive_r = (ctl_v - ctl_h) / 2;
        }

        // Now send out to motors
        DriveLeftMotor( drive_l );
        DriveRightMotor( drive_r );

        // don't hog CPU
        wait1Msec( 25 );
    }
}
task descorerControl() {
    while(true) {
        if(SensorValue[descorerLimit] == 0) {
            motor[descorer] = vexRT[Ch2];
        }
        else {
            if(vexRT[Ch2] > 0) {
                motor[descorer] = -vexRT[Ch2];
            }
            else {
                motor[descorer] = vexRT[Ch2];
            }
        }
    }
}

task frontControl() {
    while(true) {
        if(vexRT[Btn5D] == 1) {
            motor[frontRoller] = 127;
        }
        if(vexRT[Btn6D] == 1) {
            motor[frontRoller] = -127;
        }
    }
}
task flywheelCtrl() {
    while(true) {
        if(vexRT[Btn8DXmtr2] == 1) {

            motor[flywheel] = -127;
        }
        if(vexRT[Btn7DXmtr2] == 1) {
            motor[indexer] = 127;
        }
        if(vexRT[Btn7LXmtr2] == 1) {
            motor[indexer] = -127;
        }
        if(vexRT[Btn5UXmtr2] == 1) {
            motor[frontRoller] = 127;
        }
    }
}
task PlatformDrive() {
    while(true) {
    if(vexRT[Btn8U] == 1) {
        move(127);
    }
    if(vexRT[Btn8D] == 1) {
        move(-127);
    }
    }
}
task usercontrol()
{
    originalY = SensorValue[yAxis];//record the y axis value at start
    zYDif = SensorValue[zAxis] - originalY;//find the difference between 0G and 1G
    accelRatio = zYDif / 9.801;//find sensor value of 1m/s^2
    StartTask(yPosition);//start calculating position
    posAt1MSec = yPos * errorFactor;//record yPos at 1 millisecond, and account for error
    startTask(MotorSlewRateTask);
    startTask(ArcadeDrive);
    while (true)
    {
        startTask(flywheelCtrl);
        startTask(frontControl);
        startTask(PlatformDrive);
        startTask(descorerControl);
    }
}
