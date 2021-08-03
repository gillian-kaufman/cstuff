/* Author: Gillian Kaufman
 * Program: Program 4 - TimeOfDay Class File
 * Due Date: March 28, 2020
 * Purpose: Holds the method definitions used in the time test programs
 */
#include "timeofday.h"
using namespace std;

//Default Constructor
TimeOfDay::TimeOfDay()          
{
    hours = 0;
    minutes = 0;
    seconds = 0;
    meridiem = 0;
    dayOfWeek = 0;
}
//Secondary Constructor
TimeOfDay::TimeOfDay(int h, int m, int s, int mid, int d) 
{
    hours = h;
    minutes = m;
    seconds = s;
    meridiem = mid;
    dayOfWeek = d;
}
//Get and set day of week
int TimeOfDay::getDay()
{
    return dayOfWeek;
}
void TimeOfDay::setDay(int d)
{
    dayOfWeek = d;
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
int TimeOfDay::getMeridiem()
{
    return meridiem;
}
void TimeOfDay::setMeridiem(int m)
{
    meridiem = m;
}
//toString to print out TimeOfDay object
string TimeOfDay::toString()
{
    stringstream ss;
    ss << day[dayOfWeek - 1] << " " << hours << ":" << minutes << ":" << seconds << " " << meridiem;

    return ss.str();
}
//Method to get time since midnight
double TimeOfDay::getTimeSinceMidnight(int t)
{
    //Declare variables
    double h = 0, hoursSinceMidnight;
    double minSinceMidnight, secSinceMidnight;

    //Check for morning or evening
    if (getMeridiem() == 0)
    {
        h = getHours();
    }
    else if (getMeridiem() == 1)
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
    int hour = 0, militaryTime = 0;

    //Check for morning or evening
    if (getMeridiem() == 1)
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
    else if (getMeridiem() == 0)
    {
        hour = getHours();
    }
    //Calculate military time
    militaryTime = (hour * 100) + getMinutes();

    return militaryTime;
}

//Overloaded Operator Methods
TimeOfDay TimeOfDay::operator = (TimeOfDay rhs)
{
    //Copy the right-side operand and return reference to self
    int h = rhs.getHours();
    int min = rhs.getMinutes();
    int s = rhs.getSeconds();
    int mer = rhs.getMeridiem();
    int d = rhs.getDay();

    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator + (int rhs) 
{
    bool isReduced = false;
    int h = hours, min = minutes, mer = meridiem, d = dayOfWeek;

    //Increment seconds
    int s = seconds + rhs;

    //Loop to make sure numbers are within 0-59
    while (!isReduced)
    {
        if (s >= 60)
        {
            s -= 60;
            min = minutes + 1;
            isReduced = true;
        }
        if (min >= 60)
        {
            min -= 60;
            h = hours + 1;
            isReduced = true;
        }
        if (h >= 12)
        {
            if (h == 12)
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
                h -= 12;
            }
            isReduced = true;
        }
        if (d >= 7)
        {
            d -= 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator - (int rhs) 
{
    bool isReduced = false;
    int h = hours, min = minutes, mer = meridiem, s = seconds, d = dayOfWeek;

    //Decrement seconds
    s -= rhs;

    //Loop to make sure the numbers are within 0-59
    while (!isReduced)
    {
        isReduced = false;
        if (s < 0)
        {
            s += 60;
            --min;
            isReduced = true;
        }
        if (min < 0)
        {
            min += 60;
            --h;
            isReduced = true;
        }
        if (h <= 0)
        {
            if (h == 0)
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            h += 12;
            isReduced = true;
        }
        if (d < 0)
        {
            d += 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator * (int rhs) 
{
    bool isReduced = false;
    int h = hours, min = minutes, mer = meridiem, s = seconds, d = dayOfWeek;

    //Increment seconds
    min += rhs;

    //Loop to make sure numbers are within 0-59
    while (!isReduced)
    {
        if (s >= 60)
        {
            s -= 60;
            min = minutes + 1;
            isReduced = true;
        }
        if (min >= 60)
        {
            min -= 60;
            h = hours + 1;
            isReduced = true;
        }
        if (h >= 12)
        {
            if (h == 12)
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
                h -= 12;
            }
            isReduced = true;
        }
        if (d >= 7)
        {
            d -= 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator & (int rhs)
{
    bool isReduced = false;
    int h = hours, min = minutes, mer = meridiem, s = seconds, d = dayOfWeek;

    //Decrement minutes
    min -= rhs;

    //Loop to make sure the numbers are within 0-59
    while (!isReduced)
    {
        isReduced = false;
        if (s < 0)
        {
            s += 60;
            --min;
            isReduced = true;
        }
        if (min < 0)
        {
            min += 60;
            --h;
            isReduced = true;
        }
        if (h <= 0)
        {
            if (h == 0)
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            h += 12;
            isReduced = true;
        }
        if (d < 0)
        {
            d += 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator / (int rhs)
{
    bool isReduced = false;
    int h = hours, min = minutes, mer = meridiem, s = seconds, d = dayOfWeek;

    //Increment seconds
    h += rhs;

    //Loop to make sure numbers are within 0-59
    while (!isReduced)
    {
        if (s >= 60)
        {
            s -= 60;
            min = minutes + 1;
            isReduced = true;
        }
        if (min >= 60)
        {
            min -= 60;
            h = hours + 1;
            isReduced = true;
        }
        if (h >= 12)
        {
            if (h == 12)
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
                h -= 12;
            }
            isReduced = true;
        }
        if (d >= 7)
        {
            d -= 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator ^ (int rhs) 
{
    bool isReduced = false;
    int h = hours, min = minutes, s = seconds, mer = meridiem, d = dayOfWeek;

    //Decrement hours
    h -= rhs;

    //Loop to make sure the numbers are within 0-59
    while (!isReduced)
    {
        isReduced = false;
        if (s < 0)
        {
            s += 60;
            --min;
            isReduced = true;
        }
        if (min < 0)
        {
            min += 60;
            --h;
            isReduced = true;
        }
        if (h <= 0)
        {
            if (h == 0)
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            h += 12;
            isReduced = true;
        }
        if (d < 0)
        {
            d += 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator + (double rhs)
{
    //Increment all three
    int h, min, s, d = dayOfWeek, mer = meridiem;
    bool isReduced = false;

    h = rhs;
    min = (hours - h) * 60;
    s = (minutes - min) * 60;

    h += hours;
    min += minutes;
    s += seconds;
    
    //Loop to make sure numbers are within 0-59
    while (!isReduced)
    {
        if (s >= 60)
        {
            s -= 60;
            min = minutes + 1;
            isReduced = true;
        }
        if (min >= 60)
        {
            min -= 60;
            h = hours + 1;
            isReduced = true;
        }
        if (h >= 12)
        {
            if (h == 12)
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                }
                else if (mer == 1)
                {
                    mer = 0;
                    ++d;
                }
                h -= 12;
            }
            isReduced = true;
        }
        if (d >= 7)
        {
            d -= 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
TimeOfDay TimeOfDay::operator - (double rhs)
{
    //Decrement all three
    int h, min, s, mer = meridiem, d = dayOfWeek;
    bool isReduced = false;

    h = rhs;
    min = (hours - h) * 60;
    s = (minutes - min) * 60;

    h -= hours;
    min -= minutes;
    s -= seconds;

    //Loop to make sure the numbers are within 0-59
    while (!isReduced)
    {
        isReduced = false;
        if (s < 0)
        {
            s += 60;
            --min;
            isReduced = true;
        }
        if (min < 0)
        {
            min += 60;
            --h;
            isReduced = true;
        }
        if (h <= 0)
        {
            if (h == 0)
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            else
            {
                if (mer == 0)
                {
                    mer = 1;
                    --d;
                }
                else if (mer == 1)
                {
                    mer = 0;
                }
            }
            h += 12;
            isReduced = true;
        }
        if (d < 0)
        {
            d += 7;
            isReduced = true;
        }
    }
    TimeOfDay newDay(h, min, s, mer, d);
    return newDay;
}
int TimeOfDay::operator ! ()
{
    int military = toMilitary();
    //Return military time
    return military;
}
int &TimeOfDay::operator [] (int index)
{
    //Return part of TimeOfDay object based on index input
    switch (index)
    {
    case 0:
        return seconds;
    case 1:
        return minutes;
    case 2:
        return hours;
    case 3:
        return dayOfWeek;
    case 4:
        return meridiem;
    default:
        cout << "Error: that is not an option." << endl;
        break;
    }
}
