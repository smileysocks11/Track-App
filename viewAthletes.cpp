#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

/*##########################
# viewAthletes accepts a pointer to the 3d array and the num of flights
# It outputs all athletes in their separate flights
############################*/
void viewAthletes(string*** athletes, int flights)
{
    // Initialize variables
    int flight, athlete;

    // Loop through all flights
    for (flight = 0; flight < flights; flight++)
    {
        // Output the flight number
        cout << "Flight " << flight + 1 << ": \n";

        // Output heading
        cout << left << setw(25) << "Name"
            << left << setw(25) << "School"
            << left << setw(25) << "High Score" << endl;

        // Loop through all athletes in the flight
        for (athlete = 0; athlete < (sizeof(**athletes[flight]) / sizeof(string)); athlete++)
        {
            // Output information for the athlete
            for (int info = 0; info < 3; info++)
                cout << left << setw(25) << athletes[flight][athlete][info];

            cout << endl;
        }
        cout << endl;
    }
}