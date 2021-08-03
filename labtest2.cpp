// Gillian Kaufman
// Lab Test 2
// April 1, 2020
// USC Upstate CSCI 238 Dan Wooster

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	//Declare variables
	int i, j, numOfWords = 0;
	float avg = 0, consonants = 0, vowels = 0, numOfRatios = 0;
	string input, buf;
	float ratio[10000] = {};
	string words[10000] = {};
	stringstream ss;
	
	//Read input into string array
	for (i = 0; cin >> input; ++i)
	{
		words[i] = input;
		++numOfWords;
	}
	//Get number of consonants and vowels in one word
	for (i = 0; i < numOfWords; ++i)
	{
		buf = words[i];
		for (j = 0; j < buf.length(); ++j)
		{
			if (buf[j] == 'a' || buf[j] == 'e' || buf[j] == 'i' ||
					buf[j] == 'o' || buf[j] == 'u' || buf[j] == 'A' ||
					buf[j] == 'E' || buf[j] == 'I' || buf[j] == 'O' ||
					buf[j] == 'U')
			{
				++vowels;
			}
			else if ((buf[j] >= 'a' && buf[j] <= 'z') || (buf[j] >= 'A' && buf[j] <= 'Z'))
			{
				++consonants;
			}
		}
		//Compute consonant to vowel ratio and input into float array
		//If vowels == 0, ratio is 0.0
		if (vowels == 0)
		{
			ratio[i] = 0.0;
			++numOfRatios;
		}
		else
		{
			ratio[i] = consonants / vowels;
			++numOfRatios;
		}
	}
	//Compute consonant to vowel ratio average
	for (i = 0; i < numOfRatios; ++i)
	{
		avg += ratio[i];
	}
	avg /= numOfRatios;

	//Output words with ratio above average
	for (i = 0; i < numOfWords; ++i)
	{
		if (ratio[i] > avg)
		{
			ss << words[i] << " " << ratio[i] << endl;
		}
		cout << ss.str();
	}
	return 0;
}