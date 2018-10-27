//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#include "Day.h"


Day::Day()
{
	LinkedList* readings = new LinkedList();
	count = 0;
	max = 0;
	min = 0;

	buckets = new double [8]; // creating an array of potentially overfloaded buckets containing numbers
	for (int index = 0; index < 8; index++)
	{
		buckets[index] = 0; //making every value zero
	}
}

Day::~Day()
{
}

double Day::getMax()
{
	return max;
}

double Day::getMin()
{
	return min;
}


void Day::calcMax()
{
	Node* currentNode = readings.head; //accessing the head of the LL

	max = currentNode->reading; //gets the value of whatever the iterator is pointing at.
	for (currentNode = currentNode->next; currentNode != NULL; currentNode = currentNode->next)
	{
		if (currentNode->reading > max)
		{
			max = currentNode->reading;
		}
	}
}

void Day::calcMin()
{
	Node* currentNode = readings.head; //accessing the head of the LL

	min = currentNode->reading; //gets the value of whatever the iterator is pointing at.
	for (currentNode = currentNode->next; currentNode != NULL; currentNode = currentNode->next)
	{
		if (currentNode->reading < min)
		{
			min = currentNode->reading;
		}
	}
}

void Day::calcSum()
{
	for (int index = 0; index < 8; index++) //
	{
		buckets[index] = 0; //making every value zero just in case
	}

	int index = 0;
	for (Node* it = readings.head; it != NULL; it = it->next)
	{
		double temp = buckets[index] + it->reading; //adding current node reading to temp
		if (temp < 0) // if it overflows and goes to negative numbers
		{
			if (index < 8)
			{
				index++; // move to the next bucket
				buckets[index] = temp;
			}
			else 
			{
				return; //quit if all the buckets are overflown
			}
		}
		else
		{
			buckets[index] = temp; //adding value to the current bucket
		}
	}
}

double * Day::getSum()
{
	return buckets;
}

int Day::getCount()
{
	return count;
}

void Day::addReading(double c)
{
	readings.addNode(c); //adding a reading to the day
	count += 1;
}
