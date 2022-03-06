#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	vision_sensor.clear_led();
	imu_sensor.reset();
	mt1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	mt2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	sml1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	tGrabber.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
	piston.set_value(true);
}

/**
 * Runs while the robot is in the disabled state of Field Management Sypstem or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	sml1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	tGrabber.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
	piston.set_value(true);
	int strtDist = 4500;
	//move forward
	lf.move_velocity(170);
	lb.move_velocity(170);
	rf.move_velocity(170);
	rb.move_velocity(170);
	//lower rear lift
	sml1.tare_position();
	sml1.move_relative(-2000, 200);
	delay(strtDist);
	//grab with piston
	piston.set_value(false);
	
	// ctrl + k then ctrl + c to mass comment
	// ctrl + k then ctrl + u to mass uncomment
	
	//WINPOINT LEFT!!!
	//piston.set_value(false);
	//delay(100);
	//piston.set_value(true);

	//MATCH AUTON!!!!!
	//move back
	lf.move_velocity(-170);
	lb.move_velocity(-170);
	rf.move_velocity(-170);
	rb.move_velocity(-170);
	delay(strtDist - 800);
	//drop with piston
	piston.set_value(true);
	delay(300);
	//stop
	rf.move_velocity(0);
	rb.move_velocity(0);
	lf.move_velocity(0);
	lb.move_velocity(0);
	delay(100);
	//turn
	rf.move_velocity(120);
	rb.move_velocity(120);
	lf.move_velocity(-120);
	lb.move_velocity(-120);
	delay(2600);
	//stop turn and lift
	rf.move_velocity(0);
	rb.move_velocity(0);
	lf.move_velocity(0);
	lb.move_velocity(0);
	delay(100);
	//drags itself back with rear wheels
	rb.move_velocity(-170);
	lb.move_velocity(-170);
	delay(900);
	//raises rear lift to lock mogo
	sml1.move_relative(2000, 2000);
	//stops rear wheels
	rb.move_velocity(0);
	lb.move_velocity(0);

	//SKILLS AUTON!!!
	// //turn
	// rf.move_velocity(-120);
	// rb.move_velocity(-120);
	// lb.move_velocity(120);
	// lf.move_velocity(120);
	// delay(1400);
	// //back up
	// sml1.move_relative(-2000, 2000);
	// rb.move_velocity(-120);
	// rf.move_velocity(-120);
	// lf.move_velocity(-120);
	// lb.move_velocity(-120);
	// delay(5000);
	// lf.move_velocity(0);
	// lb.move_velocity(0);
	// sml1.move_relative(2000, 2000);
	// delay(1000);
	// lf.move_velocity(-120);
	// lb.move_velocity(-120);
	// //pickup with rear mogo lift
	// //turn
	// rb.move_velocity(120);
	// rf.move_velocity(120);
	// delay(1500);
	// rb.move_velocity(200);
	// rf.move_velocity(200);
	// lb.move_velocity(200);
	// lf.move_velocity(200);
	// delay(4500);
	// lf.move_velocity(0);
	// lb.move_velocity(0);
	// rf.move_velocity(0);
	// rb.move_velocity(0);
	// //drop mogo front
	// piston.set_value(true);
	// //turn and pickup colored mogo
	// lf.move_velocity(-170);
	// lb.move_velocity(-170);
	// rf.move_velocity(170);
	// rb.move_velocity(170);
	// sml1.move_absolute(-2000, 2000);
	// delay(1400);
	// piston.set_value(false);
	// delay(1000);
	// //move forward
	// lb.move_velocity(170);
	// lf.move_velocity(170);
	
	
	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	while (true) {
		//tdrive();
		arcDrive();
	}
}
