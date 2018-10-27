//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#include "Week.h"

Week::Week()
{
	days = new Day[7]; // creating an array of 7 days for one week
	count = 0;
	max = 0;
	min = 0;
	currentDay = 0;
	deltaDay = 0;

	buckets = new double[8]; // creating an array of potentially overfloaded buckets containing numbers
	for (int index = 0; index < 8; index++)
	{
		buckets[index] = 0; //makes every value zero
	}
}

Week::~Week()
{
	delete[] days; // delete that array of days because it is a destructor
}

double Week::getMax()
{
	return max;
}

double Week::getMin()
{
	return min;
}

void Week::calcMax()
{
	days[0].calcMax();
	max = days[0].getMax(); //setting max to max of day 1

	for (int i = 1; i < currentDay; i++)
	{
		days[i].calcMax();

		if (days[i].getMax() > max)
		{
			max = days[i].getMax();
		}
	}
}

void Week::calcMin()
{
	days[0].calcMin();
	min = days[0].getMin(); //setting min to min of day 1
	//cout << currentDay << endl;
	for (int i = 1; i < currentDay; i++)
	{
		cout << i << endl;
		days[i].calcMin();
		if (days[i].getMin() < min)
		{
			min = days[i].getMin();
		}
	}

}

void Week::calcSum()
{
	for (int index = 0; index < 8; index++)
	{
		buckets[index] = 0; //makes every value zero
	}
	int index = 0; //index for week bucket

	for (int i = 0; i < currentDay; i++)
	{
		days[i].calcSum(); //calc sum for each day
	}

	int tempIndex = 0; //index for daily buckets
	for (int i = 0; i < currentDay; i++) //going through each day
	{
		tempIndex = 0;
		double* tempSum = new double[8];
		tempSum = days[i].getSum(); // make temp of sum
		//cout << buckets[index] << endl;
		double temp = buckets[index] + tempSum[tempIndex]; //checking for overflow as in day
		if (temp < 0) // if it overflows and goes to negative numbers
		{
			if (index < 8)
			{
				index++; // move to the next bucket
				buckets[index] = temp;
			}
			else
			{
				return;
			}
		}
		else
		{
			buckets[index] = temp; //adding value to the current bucket
		}

		while(tempSum[tempIndex + 1] != 0) //the next bucket for the day holds something
		{
			tempIndex++;//moving to next daily bucket
			index = tempIndex; //moving to the next weekly bucket

			double temp = buckets[index] + tempSum[tempIndex];
			if (temp < 0) // if it overflows and goes to negative numbers
			{
				if (index < 8)
				{
					index++; // move to the next bucket
					buckets[index] = temp;
				}
				else
				{
					return;
				}
			}
			else
			{
				buckets[index] = temp; //adding value to the current bucket
			}
		}
	}
}

double* Week::getSum()
{
	return buckets;
}

int Week::getCount()
{
	for (int i = 0; i < currentDay; i++)
	{
		count += days[i].getCount();
	}
	
	return count;
}

void Week::addDay(Day* day)
{
	if (currentDay < 7)
	{
		days[currentDay] = *day;
		count += days[currentDay].getCount();
		currentDay++;
	}
	else
	{
		cout << "A week is thankfully only 7 days long." << endl;
	}

}

void Week::calcDelta()
{
	int delta = abs(days[1].getCount() - days[0].getCount()); //first day delta
	deltaDay = 1;
	for (int i = 2; i < currentDay; i++)
	{
		if (abs(days[i].getCount() - days[i - 1].getCount()) > delta)
		{
			deltaDay = i;
			delta = abs(days[i].getCount() - days[i - 1].getCount());
		}
	}

}

int Week::getDelta()
{
	return deltaDay;
}
