/* Author: Gillian Kaufman
 * Program: Program 2 - html.cpp
 * Due Date: Feb 19, 2020
 * Purpose: to take in user input and output in html format
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    //Declare variables
    string fullName = "";
    string description = "";
    string title = "";
    string filename = "";

    //Get input
    cout << "Enter your name: ";
    getline(cin, fullName);
    cout << "\nDescribe yourself: ";
    getline(cin, description);
    cout << "\nEnter a title for your web page: ";
    getline(cin, title);

    filename = title + ".html";

    //Declare output file
    ofstream outputFile(filename);

    //Output to file
    outputFile << "<html>\n<head>\n  <title>" << title << "</title>\n</head>\n<body>\n  <center>\n  <h1>"
        << fullName << "</h1>\n  </center>\n  <hr>\n  " << description << "\n  <hr>\n</body>\n</html>" << endl;

    return 0;
}