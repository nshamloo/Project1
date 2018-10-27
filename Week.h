//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#ifndef WEEK_H
#define WEEK_H

#include <list>
#include <iostream>
#include <iterator>
#include "Day.h"

using namespace std;

class Week
{
public:
	Week();
	~Week();
	double getMax();
	double getMin();
	void calcMax();
	void calcMin();
	void calcSum();
	double* getSum();
	int getCount();
	void addDay(Day*);
	void calcDelta();
	int getDelta();
	Day* days; //creates a pointer to an array of days
private:

	int count;
	double min;
	double max;
	int currentDay;
	int deltaDay;
	double* buckets;
};


#endif
