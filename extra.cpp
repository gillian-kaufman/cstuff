/* Author: Gillian Kaufman
 * Program: Program 2 - extra.cpp
 * Due Date: Feb 19, 2020
 * Purpose: to output a histogram of asterisks for each 1000 in population
 */
#include <iostream>
using namespace std;

int main()
{
	//Declare variables
	int i, j, sum;
	int numOfYears;

	//Get number of years
	cin >> numOfYears;

	//Declare storage arrays
	int years[1000];			//It won't let me use numOfYears here
	int population[1000];		//so I am just declaring big arrays

	//Get input
	for (i = 0; i < numOfYears; ++i)
	{
		cin >> years[i] >> population[i];
	}

	//Output title
	cout << "PRAIRIEVILLE POPULATION GROWTH\n" << endl;

	//Output histogram
	for (i = 0; i < numOfYears; ++i)
	{
		//Get number of asterisks
		sum = population[i] / 1000;

		//Display years
		cout << years[i] << ": ";
		
		//Display asterisks
		for (int j = 0; j < sum; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	//End program
	return 0;
}