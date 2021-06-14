#include "main.h"

double bkP = 0.2;//kP tuning value
double bkD = 0;//kD tuning value
double bErrorRange = 6;

void balance(){
    double error = (0 - imu_sensor.get_pitch());
    double lastError = 0;
    while(abs(error) < bErrorRange){
        error = (0 - imu_sensor.get_pitch());
        
        lb.move_velocity((error * bkP) + bkD * (error - lastError));
        lf.move_velocity((error * bkP) + bkD * (error - lastError));
        rb.move_velocity((error * bkP) + bkD * (error - lastError));
        rf.move_velocity((error * bkP) + bkD * (error - lastError));
        lastError = error;
    }
}
