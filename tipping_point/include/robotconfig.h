#pragma once//telling it to only include in any file once
#include "main.h"

//defining the devices as global
extern pros::Imu imu_sensor;
extern pros::Controller master;
extern pros::Controller partner;
extern pros::Motor lf;
extern pros::Motor rf;
extern pros::Motor lb;
extern pros::Motor rb;
extern pros::Motor mt1;
extern pros::Motor mt2;
extern pros::Motor mf;