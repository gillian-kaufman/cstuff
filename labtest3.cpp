/*	Gillian Kaufman
 *  Lab Test 3 - labtest3.cpp
 *  Due date: April 27, 2020 2 PM   */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

//Class for the gasPrice object
class gasPrice 
{
private:
    int month, day, year;
    double price;
public:
    //Constructor
    gasPrice(int m, int d, int y, double p)
    {
        month = m;
        day = d;
        year = y;
        price = p;
    }
    //Setters
    void setMonth(int a)
    {
        month = a;
    }
    void setDay(int a)
    {
        day = a;
    }
    void setYear(int a)
    {
        year = a;
    }
    void setPrice(double a)
    {
        price = a;
    }
    //Getters
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    int getYear()
    {
        return year;
    }
    double getPrice()
    {
        return price;
    }
    //Print method
    string printGasPrice()
    {
        stringstream s;
        s << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << "-" << setw(4) << year << ":" << price << endl;
        return s.str();
    }
};
int main(int argc, char** argv)
{
    //Declare variables
    int month = 0, day = 0, year = 0, buf = 0, buf1 = 0;
    int i = 0, j = 0;     
    double price = 0, sum, avg, high, low, buffer;
    string in;
    vector<int> years;
    vector<int> months;

    //Multimap of gasPrice objects
    multimap<int, gasPrice> data;

    //Maps for averages
    map<int, double> avgsPerYear;
    map<int, double> avgsPerMonth;
    map<int, double> highestperYear;
    map<int, double> lowestperYear;

    //Iterators
    multimap<int, gasPrice>::iterator iter;
    map<int, double>::iterator it;

    //Range pair
    pair<multimap<int, gasPrice>::iterator, multimap<int, gasPrice>::iterator> range;

    //File objects
    ifstream input;
    ofstream output;

    input.open("GasPrices.txt");
    output.open("output.txt");

    //Start getting input
    getline(input, in);

    //Read in input and place into specific containers
    while (!input.eof())
    {
    /*Break line apart into separate pieces and place pieces into respective variables*/
        //Get month
        stringstream ss;
        ss << in.substr(0, 2);
        ss >> month;
        ss.str("");
        //Check for multiples of same month
        if (buf1 != month)
        {
            months.push_back(month);
            buf1 = month;
        }
        //Get day
        stringstream ss1;
        ss1 << in.substr(3, 2);
        ss1 >> day;
        ss1.str("");
        //Get year
        stringstream ss2;
        ss2 << in.substr(6, 4);
        ss2 >> year;
        ss2.str("");
        //Check for multiples of the same year
        if (buf != year)
        {
            years.push_back(year);
            buf = year;
        }
        //Get price
        stringstream ss3;
        ss3 << in.substr(11, 5);
        ss3 >> price;
        ss3.str("");

        //Create gasPrice object with pieces
        gasPrice gas(month, day, year, price);

        //Place object into multimap
        data.emplace(pair <int, gasPrice> (year, gas));

        getline(input, in);
    }

    //Calculate average per year
    for (i = 0; i < years.size(); ++i)
    {
        range = data.equal_range(years[i]);
        sum = 0;
        avg = 0;
        j = 0;
        for (iter = range.first; iter != range.second; ++iter)
        {
            sum += (*iter).second.getPrice();
            ++j;
        }
        avg = sum / j;
        avgsPerYear.insert(pair<int, double>(years[i], avg));
    }
    /*Print out avg per year*/
    cout << "Average price per year is: " << endl;
    for (it = avgsPerYear.begin(); it != avgsPerYear.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    //Calculate average per month
    for (i = 0; i < months.size(); ++i)
    {
        sum = 0;
        avg = 0;
        j = 0;
        for (iter = data.begin(); iter != data.end(); ++iter)
        {
            if ((*iter).second.getMonth() == months[i])
            {
                sum += (*iter).second.getPrice();
                ++j;
            }
        }
        avg = sum / j;
        avgsPerMonth.insert(pair<int, double>(months[i], avg));
    }
    /*Print out avg per month*/
    cout << "\nAverage price per month is: " << endl;
    for (it = avgsPerMonth.begin(); it != avgsPerMonth.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    //Find highest price
    for (i = 0; i < years.size(); ++i)
    {
        range = data.equal_range(years[i]);
        high = 0;
        buffer = 0;
        for (iter = range.first; iter != range.second; ++iter)
        {
            buffer = (*iter).second.getPrice();
            if (buffer > high)
            {
                high = buffer;
            }
        }
        highestperYear.insert(pair<int, double>(years[i], high));
    }
    /*Print out highest per year*/
    cout << "\nHighest price per year is: " << endl;
    for (it = highestperYear.begin(); it != highestperYear.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    //Find lowest price
    for (i = 0; i < years.size(); ++i)
    {
        range = data.equal_range(years[i]);
        low = 1000000;
        for (iter = range.first; iter != range.second; ++iter)
        {
            buffer = (*iter).second.getPrice();
            if (buffer < low)
            {
                low = buffer;
            }
        }
        lowestperYear.insert(pair<int, double>(years[i], low));
    }
    /*Print out lowest per year*/
    cout << "\nLowest price per year is: " << endl;
    for (it = lowestperYear.begin(); it != lowestperYear.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    //Output to file
    for (auto iter = data.rbegin(); iter != data.rend(); ++iter)
    {
        output << iter->second.printGasPrice();
    }
    //Close files
    input.close();
    output.close();

    return 0;
}