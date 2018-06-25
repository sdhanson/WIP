#ifndef THRES_H
#define THRES_H

class Thresh {
public: 
	double time;
	double y;
	double derivative;

	Thresh(double t, double v, double d);
	Thresh(double t, double v);
	Thresh(double v);

	double getT();
	double getY();
	double getD();

	void setT(double t);
	void setY(double v);
	void setD(double d);

	void calcD();
};

#endif