#include "main.h"

double error;
double lastError;
double derivative;
double tkP = 0.6;
double tkD = 0.8;


void turn(double target)
{
    while(!(target - 1 < abs(imu_sensor.get_heading()) && abs(imu_sensor.get_heading()) < target + 1))
    {
        error = target - imu_sensor.get_heading();
        derivative = error - lastError;

    }
}