/* Author: Gillian Kaufman
 * Program: Program 5 - decrypt.cpp
 * Due Date: April 18, 2020
 * Purpose: to decrypt content from a given input file and output to a separate given output file
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    //Declare variables
    string buffer;
    stringstream s;
    unsigned char letter;
    int key, k, buf, flippedKey = 0;

    string inputFile = "";
    string outputFile = "";

/*Get file names*/

    //Get input file
    inputFile = argv[1];

    //Open input file
    ifstream input;
    input.open(inputFile, ios::binary);
    if (!input.is_open())
    {
        cout << "Error: cannot open file " << inputFile << endl;
        exit(0);
    }

    //Get output file
    outputFile = argv[2];

    //Open output file
    ofstream output;
    output.open(outputFile, ios::binary);
    if (!output.is_open())
    {
        cout << "Error: cannot find file " << outputFile << endl;
        exit(1);
    }

/*Get key at start of file*/
    getline(input, buffer);
    s << buffer;
    s >> key; 

/*Flip key for second shift*/
    k = key;
    while (k != 0)
    {
        buf = k % 10;
        flippedKey = (flippedKey * 10) + buf;
        k /= 10;
    }
    
    //Get first character from file after key
    letter = input.get();

/*Read characters from input file and place in output file*/
    while (!input.eof())
    {
        //Shift back each character by flipped key amount
        letter -= flippedKey;

        //Don't go over 255
        if (letter > 255)
        {
            letter = letter % 255;
        }

        //Shift back again with original key
        letter -= key;

        //Don't go over 255 (again)
        if (letter > 255)
        {
            letter = letter % 255;
        }

        //Output each shifted character to output file
        output.put(letter);

        //Move to next character
        letter = input.get();
    }

/*Close files*/
    input.close();
    output.close();
    return 0;
}