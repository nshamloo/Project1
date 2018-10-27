//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#include <iostream>
#include <string>
#include "Day.h"
#include "Week.h"
using namespace std;

void userInter();


int main()
{
	userInter();
	system("pause");
	return 0;
}

void userInter()
{
	cout << "Hello. Please enter bloodsugar readings." << endl;
	cout << "Letter D or word Day will show the daily summary thus far." << endl;
	cout << "Letter W or word Week will show the Weekly summary thus far." << endl;
	cout << "Letter N or word Next will increment to the next day." << endl;
	
	Week* weeks = new Week[2]; // create array of 2 weeks
	Day* day = new Day();
	int currentWeek = 0; // where you are now
	int currentDay = 0; // where you are now in terms of days
	string input = ""; 
	weeks[currentWeek].addDay(day);
	while (true) //run forever
	{
		cout << "Enter blood sugar reading or any of the options presented above." << endl;
		cin >> input;
		if((input == "N") || (input == "Next")) 
		{
			if (currentDay + 1 > 6)
			{
				currentWeek++; // move to the next week
			}
			weeks[currentWeek].addDay(day); // adding day to the current week
			currentDay++;
			cout << "Next day is: " << currentDay + 1 << endl;
		}
		else if ((input == "W") || (input == "Week"))
		{
			for (int index = 0; index < currentWeek+1; index++)
			{
				weeks[index].calcMin();
				weeks[index].calcMax();
				weeks[index].calcDelta();
				weeks[index].calcSum();
				double* tempSum = weeks[0].getSum(); //getting sum for week 1

				cout << "Maximum for week " << currentWeek+1 << " is: " << weeks[index].getMax()<< endl;
				cout << "Minimum for week " << currentWeek+1 << " is: " << weeks[index].getMin() << endl;
				cout << "Day with largest delta for week " << currentWeek + 1 << " is: " << weeks[index].getDelta() << endl;
				cout << "Number of valid blood sugar readings for week " << currentWeek + 1 << " is: " << weeks[index].getCount() << endl;
				for (int i = 0; i < 8; i++)
				{
					cout << "Sum for week 1 is: " << tempSum[i] << endl;
					if (tempSum[i + 1] == 0)
					{
						break; //exit out of the loop if the rest of the buckets are empty
					}
				}
			}
		}
		else if ((input == "D") || (input == "Day"))
		{
			//calculating min/max/ and sum for the current day of the current week:
			weeks[currentWeek].days[currentDay].calcMin();
			weeks[currentWeek].days[currentDay].calcMax();
			weeks[currentWeek].days[currentDay].calcSum();
			double* tempSum = weeks[currentWeek].days[currentDay].getSum(); //getting sum for current week

			cout << "Maximum for current day is: " << weeks[currentWeek].days[currentDay].getMax() << endl;
			cout << "Minimum for current day is: " << weeks[currentWeek].days[currentDay].getMin() << endl;
			cout << "Count for the day is: " << weeks[currentWeek].days[currentDay].getCount() << endl;
			for (int i = 0; i < 8; i++) //in case of an overflow, print all buckets with overflow numbers
			{
				cout << "Sum for current day is: " << tempSum[i] << endl;
				if (tempSum[i + 1] == 0)
				{
					break; //exit out of the loop if the rest of the buckets are empty
				}
			}
		}
		else
		{
			double numb = stof(input); // convert the input string into float
			if (numb > 0) //making sure it is valid
			{
				weeks[currentWeek].days[currentDay].addReading(numb); //adding reading to the current day of the current week
			}
		}
	}
}

