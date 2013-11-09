//Owen Holloway, owen.holloway101@gmail.com

//RoboSquadUnited 2013
//Team-51 Australia


//Config for motors sensors and the such
#pragma config(Hubs,   S1, MatrxRbtcs, none,     none,     none)
#pragma config(Hubs,   S2, MatrxRbtcs, none,     none,     none)
#pragma config(Sensor, S1,           ,sensorI2CMuxController)
#pragma config(Sensor, S2,           ,sensorI2CMuxController)
#pragma config(Motor,  motorA,          MotorA, tmotorNXT, PIDControl, encoder)	//NXT Motors
#pragma config(Motor,  motorB,          MotorB, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          MotorC, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_Matrix_S1_1, MotorD, tmotorMatrix, openLoop)					//Matrix Motors
#pragma config(Motor,  mtr_Matrix_S1_2, MotorE, tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S1_3, MotorF, tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S1_4, MotorG, tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S2_1, MotorH, tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S2_2, MotorI, tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S2_3, MotorJ, tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S2_4, MotorK, tmotorMatrix, openLoop)
#pragma config(Servo, srvo_Matrix_S1_1, servo1, tServoStandard)								//Matrix servos
#pragma config(Servo, srvo_Matrix_S1_2, servo2, tServoStandard)
#pragma config(Servo, srvo_Matrix_S1_3, servo3, tServoStandard)
#pragma config(Servo, srvo_Matrix_S1_4, servo4, tServoStandard)
#pragma config(Servo, srvo_Matrix_S2_1, servo5, tServoStandard)
#pragma config(Servo, srvo_Matrix_S2_2, servo6, tServoStandard)
#pragma config(Servo, srvo_Matrix_S2_3, servo7, tServoStandard)
#pragma config(Servo, srvo_Matrix_S2_4, servo8, tServoStandard)

//External drivers
#include "JoystickDriver.c"

#define false 0;
#define true 1;

//loop for program, this ensures a breakable infinte loop
int running = 1;

/*These are program wide accessable values for the motor speeds, the motors could be set directly
but this allows for mainipulation in other threads with ease. */
//NXT motor speeds
int motorASpeed = 0;
int motorBSpeed = 0;
int motorCSpeed = 0;

//Matrix motor speeds
int motorDSpeed = 0;
int motorESpeed = 0;

#include "nxt-motors.h"
#include "control.h"

task main()
{
	//Motors and servos tasks
	StartTask(nxtMotors);

	//analog controller and maths tasks
	StartTask(controllerToMotors);

	while(running) {
	}
}
