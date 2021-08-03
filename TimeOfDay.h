/* Author: Gillian Kaufman
 * Program: Program 3 - TimeOfDay Header File
 * Due Date: March 7, 2020
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
    
    double hours;
    int minutes, seconds;
    string meridiem;          //AM or PM string variable
    string day[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
public:
    //Constructors
    TimeOfDay();
    TimeOfDay(double h, int m, int s, string mid);

    //Get Methods
    double getHours();
    int getMinutes();
    int getSeconds();
    string getMeridiem();

    //Set Methods
    void setHours(double h);
    void setMinutes(int m);
    void setSeconds(int s);
    void setMeridiem(string m);

    //toString Method
    string toString();

    //getTimeSinceMidnight Method
    double getTimeSinceMidnight(int t);

    //toMilitary Method
    int toMilitary();
};
#endif