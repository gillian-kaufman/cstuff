/* Author: Gillian Kaufman
 * Program: Lab Test 1 - TempAverages 
 * Due Date: Feb 7, 2020
 * Purpose: to compute the temperature averages of even days and odd days
 */

#include <iostream>

using namespace std;

int main()
{
	//Declare variables
	float dayOne, dayTwo, dayThree, dayFour, dayFive, daySix, daySeven, evenAvg, oddAvg, evenSum, oddSum;

	//Get input for each day
	cin >> dayOne >> dayTwo >> dayThree >> dayFour >> dayFive >> daySix >> daySeven;

	//Compute odd day average
	oddSum = (dayOne + dayThree + dayFive + daySeven);
	oddAvg = oddSum / 4;

	//Compute even day average
	evenSum = (dayTwo + dayFour + daySix);
	evenAvg = evenSum / 3;

	//Output result
	cout << evenAvg << " " << oddAvg << endl;
	return 0;
}
