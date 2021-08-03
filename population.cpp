/* Author: Gillian Kaufman
 * Program: Program 2 - population.cpp
 * Due Date: Feb 19, 2020
 * Purpose: to output a histogram of asterisks for each 1000 in population
 */
#include <iostream>
using namespace std;

int main()
{
	//Declare variables
	int i, j, sum, year = 1910;
	int population[6];

	//Get input
	for (i = 0; i < 6; ++i)
	{
		cin >> population[i];
	}
	//Output title
	cout << "PRAIRIEVILLE POPULATION GROWTH\n" << endl;

	//Output histogram
	for (i = 0; i < 6; ++i)
	{
		//Get number of asterisks
		sum = population[i] / 1000;
		//Display years
		cout << year << ": ";		
		//Display asterisks
		for (int j = 0; j < sum; ++j)	
		{
			cout << "*";				
		}
		cout << endl;
		//Increment year by 20
		year += 20;
	}
	//End program
	return 0;
}