#include "main.h"

void autonLeft(){
    piston.set_value(false);
    pros::delay(350);
    piston.set_value(true);
    pros::delay(350);
    piston.set_value(false);
}