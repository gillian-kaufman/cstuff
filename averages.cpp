/* Author: Gillian Kaufman
 * Program: Program 2 - averages.cpp
 * Due Date: Feb 19, 2020
 * Purpose: to calculate the average of each letter grade scale from given input
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Declare variables
    int grade;
    int numOfAs = 0, numOfBs = 0, numOfCs = 0, numOfDs = 0, numOfFs = 0, numOfInvalids = 0;
    float sumOfAs = 0, sumOfBs = 0, sumOfCs = 0, sumOfDs = 0, sumOfFs = 0;

    //Get input
    while (cin >> grade)
    {
        //Conditionals for the different grade levels
        if (grade > 100 || grade < 0)
        {
            ++numOfInvalids;
        }
        else if (grade > 89 && grade <= 100)
        {
            sumOfAs += grade;
            ++numOfAs;
        }
        else if (grade > 79 && grade < 90)
        {
            sumOfBs += grade;
            ++numOfBs;
        }
        else if (grade > 69 && grade < 80)
        {
            sumOfCs += grade;
            ++numOfCs;
        }
        else if (grade > 59 && grade < 70)
        {
            sumOfDs += grade;
            ++numOfDs;
        }
        else if (grade > 0 && grade < 60)
        {
            sumOfFs += grade;
            ++numOfFs;
        }
    }

    //Output averages
    if (numOfAs == 0)
        cout << "A N/A" << endl;
    else
        cout << "A " << fixed << setprecision(2) << (sumOfAs / numOfAs) << endl;
    
    if (numOfBs == 0)
        cout << "B N/A" << endl;
    else
        cout << "B " << fixed << setprecision(2) << (sumOfBs / numOfBs) << endl;
    
    if (numOfCs == 0)
        cout << "C N/A" << endl;
    else
        cout << "C " << fixed << setprecision(2) << (sumOfCs / numOfCs) << endl;
    
    if (numOfDs == 0)
        cout << "D N/A" << endl;
    else
        cout << "D " << fixed << setprecision(2) << (sumOfDs / numOfDs) << endl;
   
    if (numOfFs == 0)
        cout << "F N/A" << endl;
    else
        cout << "F " << fixed << setprecision(2) << (sumOfFs / numOfFs) << endl;
   
    if (numOfInvalids == 0)
        cout << "Invalid N/A" << endl;
    else
        cout << "Invalid " << fixed << setprecision(2) << numOfInvalids << endl;
    

    return 0;
}
