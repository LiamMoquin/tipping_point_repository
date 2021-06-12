#include "main.h"

double kP = 0.2;//kP tuning value
double kD = 0;//kD tuning value

void balance(){
    double error = (0 - Imu_sensor.get_pitch());
    double lastError = 0;
    while(6 < error && error < -6){
        error = (0 - Imu_sensor.get_pitch());
        
        lb.move_velocity((error * kP) + kD * (error - lastError));
        lf.move_velocity((error * kP) + kD * (error - lastError));
        rb.move_velocity((error * kP) + kD * (error - lastError));
        rf.move_velocity((error * kP) + kD * (error - lastError));
        error = lastError;
    }
}
