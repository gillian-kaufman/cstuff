/* Author: Gillian Kaufman
 * Program: Program 3 - TimeOfDay Class File
 * Due Date: March 7, 2020
 * Purpose: Holds the method definitions used in the time test programs
 */
#include "TimeOfDay.h"
using namespace std;

//Default Constructor
TimeOfDay::TimeOfDay()          
{
    hours = 0;
    minutes = 0;
    seconds = 0;
    meridiem = "AM";
}
//Secondary Constructor
TimeOfDay::TimeOfDay(double h, int m, int s, string mid) 
 {
    hours = h;
    minutes = m;
    seconds = s;
    meridiem = mid;
}
//Get and set hours
double TimeOfDay::getHours()
{
    return hours;
}
void TimeOfDay::setHours(double h)
{
    hours = h;
}
//Get and set minutes
int TimeOfDay::getMinutes()
{
    return minutes;
}
void TimeOfDay::setMinutes(int m)
{
    minutes = m;
}
//Get and set seconds
int TimeOfDay::getSeconds()
{
    return seconds;
}
void TimeOfDay::setSeconds(int s)
{
    seconds = s;
}
//Get and set AM or PM
string TimeOfDay::getMeridiem()
{
    return meridiem;
}
void TimeOfDay::setMeridiem(string m)
{
    meridiem = m;
}
//toString to print out TimeOfDay object
string TimeOfDay::toString()
{
    stringstream ss;
    ss << hours << ":" << minutes << ":" << seconds << " " << meridiem;

    return ss.str();
}
//Method to get time since midnight
double TimeOfDay::getTimeSinceMidnight(int t)
{
    //Declare variables
    double h, hoursSinceMidnight;
    double minSinceMidnight, secSinceMidnight;

    //Check for morning or evening
    if (getMeridiem() == "AM")
    {
        h = getHours();
    }
    else if (getMeridiem() == "PM")
    {
        //Check for 12 PM
        if (getHours() == 12)
        {
            h = getHours();
        }
        else
        {
            h = getHours() + 12.0;
        }
    }
    //Time since midnight calculations
    secSinceMidnight = 86400 - (h * 3600);
    minSinceMidnight = 1440 - (h * 60);
    hoursSinceMidnight = 24.0 - (static_cast<double>(minSinceMidnight) / 60.0);

    //Return hours, minutes, or seconds since midnight
    if (t == 0)
    {
        return hoursSinceMidnight;
    }
    else if (t == 1)
    {
        return minSinceMidnight;
    }
    else if (t == 2)
    {
        return secSinceMidnight;
    }
}
//Method to get military time
int TimeOfDay::toMilitary()
{
    //Declare variables
    int hour, militaryTime = 0;

    //Check for morning or evening
    if (getMeridiem() == "PM")
    {
        //Check for 12 PM
        if (getHours() == 12)
        {
            hour = getHours();
        }
        else
        {
            hour = getHours() + 12.0;
        }
    }
    else if (getMeridiem() == "AM")
    {
        hour = getHours();
    }
    //Calculate military time
    militaryTime = (hour * 100) + getMinutes();

    return militaryTime;
}
