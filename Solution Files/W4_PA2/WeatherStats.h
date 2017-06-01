#pragma once
#include <iostream>
using namespace std;

class WeatherStats;		//Forward declaration

//Function prototype for the overloaded stream operator
ostream &operator << (ostream &, const WeatherStats &);

class WeatherStats
{
private:
	double monthRain;
	double monthSnow;
	int sunnyDays;
public:
	//#######################################################################################################
	//Default constructor which initializes all values to 0.												#
	//#######################################################################################################
	WeatherStats()
	{
		monthRain = 0;
		monthSnow = 0;
		sunnyDays = 0;
	}

	//#######################################################################################################
	//Destructor.																							#
	//#######################################################################################################
	~WeatherStats()
	{	}

	//#######################################################################################################
	//Mutator functions for each of the member variables.													#
	//#######################################################################################################
	void setMonthRain(double r)
	{ monthRain = r; }
	
	void setMonthSnow(double s)
	{ monthSnow = s; }

	void setSunnyDays(double d)
	{ sunnyDays = d; }

	//#######################################################################################################
	//Accessor functions for each of the member variables.													#
	//#######################################################################################################
	double getMonthRain()
	{ return monthRain; }

	double getMonthSnow()
	{ return monthSnow; }

	int getSunnyDays()
	{ return sunnyDays; }

	//#######################################################################################################
	//Overloaded = operator (Defined in WeatherStats.cpp).													#
	//#######################################################################################################
	void operator=(const WeatherStats &);

	//#######################################################################################################
	//Friends (needed for overloaded << operator to work).													#
	//#######################################################################################################
	friend ostream &operator << (ostream &, const WeatherStats &);
};

