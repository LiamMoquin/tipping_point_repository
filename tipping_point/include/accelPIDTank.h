#pragma once
#include "main.h"

extern double degToRotate;

void sDSAccel(double dist, double startPower, double endPower, double rampUpValue);

void cDSAccel(double startPower, double endPower, double rampUpValue);

void DSDecel(double startPower, double endPower, double rampUpValue);