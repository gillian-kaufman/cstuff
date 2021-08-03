/* Author: Gillian Kaufman
 * Program: Program 4 - TimeOfDay Header File
 * Due Date: March 28, 2020
 * Purpose: Holds the method prototypes used in the time test programs
 */
#ifndef TIMEOFDAY_H
#define TIMEOFDAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <locale>
using namespace std;

class TimeOfDay
{
private:
    int dayOfWeek, hours, minutes, seconds, meridiem;
    string day[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
public:
    //Constructors
    TimeOfDay();
    TimeOfDay(int h, int m, int s, int mid, int d);

    //Get Methods
    int getDay();
    double getHours();
    int getMinutes();
    int getSeconds();
    int getMeridiem();

    //Set Methods
    void setDay(int d);
    void setHours(double h);
    void setMinutes(int m);
    void setSeconds(int s);
    void setMeridiem(int m);

    //toString Method
    string toString();

    //getTimeSinceMidnight Method
    double getTimeSinceMidnight(int t);

    //toMilitary Method
    int toMilitary();

    //Overloaded Operator Methods
    TimeOfDay operator = (TimeOfDay a);
    TimeOfDay operator + (int a);
    TimeOfDay operator - (int a);
    TimeOfDay operator * (int a);
    TimeOfDay operator & (int a);
    TimeOfDay operator / (int a);
    TimeOfDay operator ^ (int a);
    TimeOfDay operator + (double a);
    TimeOfDay operator - (double a);
    int operator ! ();
    int &operator [] (int i);
};
#endif