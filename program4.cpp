#include <iostream>
#include "timeofday.h"
using namespace std;

int main() {

    // if you did A version then comment out line 7 otherwise comment out line 6
    TimeOfDay t1(11, 59, 59, 0, 1); // for A version
    //TimeOfDay t1(11,59,59,0); // for B or C version
    TimeOfDay t2;
    t2 = t1 + 10; // add 10 seconds to the timeofday
    cout << "add 10 seconds to " << t1.toString() << " and it will be " << t2.toString() << endl;

    t2 = t1 + 1.5; // add 1 hour and 30 minutes to the timeofday (12.29.59)
    cout << "add 1.5 hours to " << t1.toString() << " and it will be " << t2.toString() << endl;

    t2 = t1 * 20; // add 20 minutes to the timeofday
    cout << "add 20 minutes to " << t1.toString() << " and it will be " << t2.toString() << endl;

    t2 = t1 / 5; // add 5 hours to the timeofday
    cout << "add 5 hours to " << t1.toString() << " and it will be " << t2.toString() << endl;

    t2 = t1 - 1.5; // subtract 1.5 hours to the timeofday
    cout << "subtract 1.5 hours from " << t1.toString() << " and it will be " << t2.toString() << endl;

    t2 = t1;
    t2[0] = 55; // make timeofday's seconds be 55
    cout << "make seconds be 55 and " << t1.toString() << " will be " << t2.toString() << endl;

    t2 = t1;
    t2[1] = 40; // make timeofday's minutes be 40
    cout << "make minutes be 40 and " << t1.toString() << " will be " << t2.toString() << endl;

    t2 = t1;
    t2[2] = 10; // make timeofday's hours be 10 (which means adjusting to PM)
    cout << "make hours be 10 and " << t1.toString() << " will be " << t2.toString() << endl;

    //
    // if you did NOT do the A version of program 3 then comment out the next 3 lines of code
    //
    t2 = t1;
    t2[3] = 3; // make timeofday's day of week be 3 (Wednesday)
    cout << "make dow be 3 and " << t1.toString() << " will be " << t2.toString() << endl;

    t2 = t1;
    t2[4] = 0; // make timeofday's AM/PM be AM
    cout << "make AM/PM be 0 and " << t1.toString() << " will be " << t2.toString() << endl;

    // if you did NOT do the B version for program 3 then comment out this next line
    cout << "military time for " << t1.toString() << " is " << !t1 << endl;
}