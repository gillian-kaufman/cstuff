/* Author: Gillian Kaufman
 * Program: Program 3 - testTimeC.cpp
 * Due Date: March 7, 2020
 * Purpose: tester for TimeOfDay class 
 */
#include "TimeOfDay.h"
#include <string>
using namespace std;

int main(int argv, char** argc)
{
    //Declare variables
    enum Time { HOURS, MINUTES, SECONDS };
    int mm = 0, ss = 0;
    double h = 0;
    string mer, time;
    stringstream placeholder, placeholder2, placeholder3;

    //Get time input
    getline(cin, time);

    //Check length of time input
    if (time.length() == 10)
    {
        placeholder << time.substr(0, 1);
        placeholder >> h;
        placeholder2 << time.substr(2, 2);
        placeholder2 >> mm;
        placeholder3 << time.substr(5, 2);
        placeholder3 >> ss;
        mer = time.substr(8, 2);
    }
    else if (time.length() == 11)
    {
        placeholder << time.substr(0, 2);
        placeholder >> h;
        placeholder2 << time.substr(3, 2);
        placeholder2 >> mm;
        placeholder3 << time.substr(6, 2);
        placeholder3 >> ss;
        mer = time.substr(9, 2);
    }

    //Object declaration
    TimeOfDay day = TimeOfDay(h, mm, ss, mer);

    //Banner print statement
    cout << "TIME" << setw(15) << "HOURS" << setw(10) << "MINUTES" << setw(11) << "SECONDS" << endl;

    //Output print statement
    cout << day.toString() << setw(8) << right << fixed << setprecision(3) << day.getTimeSinceMidnight(HOURS) << fixed << setprecision(0) << setw(10) << right << day.getTimeSinceMidnight(MINUTES) << setw(11) << right << day.getTimeSinceMidnight(SECONDS) << endl; 

    return 0;
}