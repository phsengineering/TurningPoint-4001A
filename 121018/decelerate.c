#pragma config(Motor,  port2,           one,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           two,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           three,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           four,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
motor[one] = 127;
motor[two] = 127;
motor[three] = 127;
motor[four] = 127
wait(60);
for(int i = 127; i>0; i-=20) {
	
motor[one] = i;
motor[two] = i;
motor[three] = i;
motor[four] = i;
wait1Msec(1);
}


}
