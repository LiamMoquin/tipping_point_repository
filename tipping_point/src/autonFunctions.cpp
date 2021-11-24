#include "main.h"

void trigCalc(double a = 54, double o = 27){
    
    double angle = tan(o/a);
    double dist = hypot(a, o);
    print(0, 0, angle);
    print(1, 0, dist);
    //turn to angle
    //move dist
}