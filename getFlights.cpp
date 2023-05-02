/*
 * BRIGHTON HILYARD'S FILE
*/

#include <iostream>
#include <string>
using namespace std;

int getFlights(int& num_athletes) {
    /*
     * gets the amount of flights for the meet
     * returns to main
     */
    int flights = 0;
    cout << "\nThere are " << num_athletes << " athletes attending the meet.\n";
    cout << "How any flights would you like in this meet? ";
    cin >> flights;

    return flights;
}
