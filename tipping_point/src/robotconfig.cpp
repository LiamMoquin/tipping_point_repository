#include "robotconfig.h"

pros::Controller master (E_CONTROLLER_MASTER);
pros::Motor lf (1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor rf (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor lb (3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor rb (4, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

void vexcodeInit(void){
    //nothing to initialize
}