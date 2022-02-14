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
	//piston.set_value(false);
	//towerMove(960, 75);

	//right side
	
	lb.move_velocity(1000);
	lf.move_velocity(1000);
	rb.move_velocity(1000);
	rf.move_velocity(1000);
	delay(1700);
	//motorStop();
	piston.set_value(false);
	//rf.move_velocity(-1000);
	//rb.move_velocity(-1000);
	//lf.move_velocity(-1000);
	//lb.move_velocity(-1000);
	//delay(1600);
	//motorStop();


	/*piston.set_value(false);
	rf.move_velocity(1000);
	rb.move_velocity(1000);
	lf.move_velocity(-1000);
	lb.move_velocity(-1000);
	delay(600);
	rb.move_velocity(-1000);
	rf.move_velocity(-1000);
	lb.move_velocity(-1000);
	lf.move_velocity(-1000);
	delay(1000);
	lf.move_velocity(1000);
	lb.move_velocity(1000);
	rf.move_velocity(1000);
	rb.move_velocity(1000);*/

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
		pros::vision_signature_s_t BLUE_SIG =
		  pros::Vision::signature_from_utility(1, -2501, -1593, -2047, 5517, 11217, 8367, 2.100, 0);
		vision_sensor.set_signature(1, BLUE_SIG);
		vision_object_s_t rtn = vision_sensor.get_by_sig(1, 0, BLUE_SIG);
		std::cout <<"sig: " << rtn.signature;
		delay(2);
		arcDrive();
	}
}
