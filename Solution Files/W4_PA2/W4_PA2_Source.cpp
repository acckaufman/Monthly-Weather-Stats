//This program demonstrates use of the LinkedList class created in Week 4, Assignment 1.
//A linked list of class type WeatherStats is created and demonstrated.
#include "LinkedList.h"
#include "WeatherStats.h"
#include <iostream>
#include <iomanip>
using namespace std;

void displayList(LinkedList<WeatherStats> &);				//To display the contents of the weather stats linked list
void calcStats(LinkedList<WeatherStats> &, int);			//To find the month with the highest and lowest amount of rain, snow, and sunny days

int main()
{
	//Create an instance of our LinkedList class, of the WeatherStats data type.
	LinkedList<WeatherStats> statsList;

	int num;		//Variable for how many months the user wants to enter stats for

	cout << "How many months would you like to enter weather statistics for? ";
	cin >> num;

	//Create a loop to get the user's data about the weather stats for each month.
	//We will then fill a temporary instance of WeatherStats with the information,
	//and append the WeatherStats object to the end of our statsList linked list created above.

	//Create a temporary instance of our WeatherStats class, to prompt the user for input,
	//and other temp variables to hold the user's data.
	WeatherStats temp;
	double tempDouble;
	int tempInt;

	for (int count = 0; count < num; count++)
	{
		cout << "Enter the rainfall for month " << (count + 1) << ": ";
		cin >> tempDouble;
		temp.setMonthRain(tempDouble);
		cout << "Enter the snowfall for month " << (count + 1) << ": ";
		cin >> tempDouble;
		temp.setMonthSnow(tempDouble);
		cout << "Enter the number of sunny days for month " << (count + 1) << ": ";
		cin >> tempDouble;
		tempInt = static_cast<int>(tempDouble);		//To guard against accidental floating-point input by the user
		temp.setSunnyDays(tempInt);

		//The temp instance of WeatherStats now holds all of the necessary information.
		//Append the instance to the statsList linked list we created at the beginning of main().
		statsList.appendItem(temp);

	}	//Loop continues until the user has entered all the information for each month.

	//Display all of the months that the user entered information for, using the displayList() function defined outside of main().
	cout << endl;
	displayList(statsList);

	//Calculate and display the stats for highest and lowest amount of rainfall, snowfall, and sunny days.
	calcStats(statsList, num);

	cout << endl;
	system("pause");
	return 0;
}

//Displays the contents of the linked list passed as a parameter, using the displayList() member function of the LinkedList class.
void displayList(LinkedList<WeatherStats> &list)
{
	list.displayList();
	cout << endl;
}

void calcStats(LinkedList<WeatherStats> &list, int num)
{
	WeatherStats initialize;		//To initialize the variables below with values for the first item in the list, as a basis for comparison
	initialize = list.getItem(0);	//Get the first item in the linked list, to establish a basis for the variables below.
									//This way, the code will still work if the user only enters data for one month.

	//Variables to hold amounts for the most and least rain, snow, and number of sunny days.
	double maxRain = initialize.getMonthRain();
	double minRain = initialize.getMonthRain();
	double maxSnow = initialize.getMonthSnow();
	double minSnow = initialize.getMonthSnow();
	int maxSun = initialize.getSunnyDays();
	int minSun = initialize.getSunnyDays();

	//Variables to hold the indexes of the months corresponding to the most and least rain, snow, and number of sunny days.

	int maxRainIndex = 0;
	int minRainIndex = 0;
	int maxSnowIndex = 0;
	int minSnowIndex = 0;
	int maxSunIndex = 0;
	int minSunIndex = 0;

	/*
	cout << endl << endl << "For testing purposes only:" << endl;
	cout << initialize.getMonthRain() << endl;
	cout << initialize.getMonthSnow() << endl;
	cout << initialize.getSunnyDays() << endl << endl;
	*/

	WeatherStats temp;		//Temporary variable to hold an item retrieved from the linked list
	int index;				//Loop counter variable

	//Get each item in the linked list, and use it to compare values already stored in the variables listed above
	for (index = 1; index < num; index++)
	{
		//Get the item from the linked list
		temp = list.getItem(index);
		
		//Find the month with the greatest rainfall.
		if (temp.getMonthRain() > maxRain)
		{
			maxRain = temp.getMonthRain();
			maxRainIndex = index;
		}

		//Find the month with the least rainfall.
		if (temp.getMonthRain() < minRain)
		{
			minRain = temp.getMonthRain();
			minRainIndex = index;
		}

		//Find the month with the greatest snowfall.
		if (temp.getMonthSnow() > maxSnow)
		{
			maxSnow = temp.getMonthSnow();
			maxSnowIndex = index;
		}

		//Find the month with the least snowfall.
		if (temp.getMonthSnow() < minSnow)
		{
			minSnow = temp.getMonthSnow();
			minSnowIndex = index;
		}

		//Find the month with the most sunny days.
		if (temp.getSunnyDays() > maxSun)
		{
			maxSun = temp.getSunnyDays();
			maxSunIndex = index;
		}

		//Find the month with the least sunny days.
		if (temp.getSunnyDays() < minSun)
		{
			minSun = temp.getSunnyDays();
			minSunIndex = index;
		}
	}

	//Display the results.

	cout << fixed << showpoint << setprecision(2);
	cout << "The month with the most rainfall was Month #" << (maxRainIndex + 1) << ", with " << maxRain << " inches of rain." << endl;
	cout << "The month with the least rainfall was Month #" << (minRainIndex + 1) << ", with " << minRain << " inches of rain." << endl;
	cout << "The month with the most snowfall was Month #" << (maxSnowIndex + 1) << ", with " << maxSnow << " inches of snow." << endl;
	cout << "The month with the least snowfall was Month #" << (minSnowIndex + 1) << ", with " << minSnow << " inches of snow." << endl;
	cout << "The month with the most sunny days was Month #" << (maxSunIndex + 1) << ", with " << maxSun << " sunny days." << endl;
	cout << "The month with the least sunny days was Month #" << (minSunIndex + 1) << ", with " << minSun << " sunny days." << endl;

}