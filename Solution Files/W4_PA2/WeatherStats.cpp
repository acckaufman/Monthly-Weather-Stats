#include "WeatherStats.h"

//#######################################################################################################
//Overloaded = operator for use in the getItem() function.												#
//#######################################################################################################
void WeatherStats::operator=(const WeatherStats &right)
{
	monthRain = right.monthRain;
	monthSnow = right.monthSnow;
	sunnyDays = right.sunnyDays;
}

//#######################################################################################################
//Overloaded output << operator for use in the displayList() function.									#
//#######################################################################################################
ostream &operator << (ostream &strm, const WeatherStats &obj)
{
	strm << obj.monthRain << " inches of rain, " << obj.monthSnow << " inches of snow, " << obj.sunnyDays << " sunny days.";
	return strm;
}