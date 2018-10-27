//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#ifndef DAY_H
#define DAY_H

#include <iostream>
#include "List.h"
using namespace std;

class Day
{
public:
	Day();
	~Day();
	void calcMax();
	void calcMin();
	double getMax();
	double getMin();
	void calcSum();
	double* getSum();
	int getCount();
	void addReading(double);

private:
	LinkedList readings;
	int count;
	double max; //all floats are double 
	double min;
	double* buckets;

};


#endif
