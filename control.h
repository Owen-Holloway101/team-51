task controllerToMotors() {
while(running){
	//The joysticks have a value from -127 to +127
	motorASpeed = joystick.joy1_y1;
	motorBSpeed = joystick.joy1_y2;
}
}
