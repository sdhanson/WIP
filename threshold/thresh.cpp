#include "thresh.h"

using namespace std;

Thresh::Thresh(double t, double v, double d) {
	time = t;
	y = v;
	derivative = d;
}

Thresh::Thresh(double t, double v) {
	time = t;
	y = v;
	derivative = -100;
}

Thresh::Thresh(double v) {
	time = -100;
	y = v;
	derivative = -100;
}


double Thresh::getT() {
	if(time != -100) {
		return time;
	}
	return -100;
	
}

double Thresh::getY() {
	if(y != -100) {
		return y;
	}
	return -100;
}

double Thresh::getD() {
	if(derivative != -100) {
		return derivative;
	}
	return -100;
}

void Thresh::setT(double t) {
	time = t;
}

void Thresh::setY(double v) {
	y = v;
}

void Thresh::setD(double d) {
	derivative = d;
}

void Thresh::calcD() {}