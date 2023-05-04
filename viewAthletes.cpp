// Carolyn Henderson
#include <iostream>
#include <string>
#include <iomanip>
#include "Athletes.h"
using namespace std;



/*##########################
# viewAthletes accepts an array of athletes, the num of flights,
# and the number of athletes in the array
# It outputs all athletes in their separate flights
############################*/
void viewAthletes(Athletes athletes[], int flights, int numAthletes)
{
    // Initialize variables
    int flight, athlete;

    // Loop through all flights
    for (flight = 0; flight < flights; flight++)
    {
        // Output the flight number
        cout << "Flight " << flight + 1 << ": \n";

        // Output heading
        cout << left << setw(30) << "Name"
            << left << setw(30) << "School"
            << left << setw(30) << "High Score" << endl;

        // Loop through all athletes in the array
        for (athlete = 0; athlete < numAthletes; athlete++)
        {
            // Only output info if the athlete is in the current flight
            if (athletes[athlete].flightNum == flight + 1)
            {
                // Output information for the athlete
                cout << left << setw(30) << athletes[athlete].name;
                cout << left << setw(30) << athletes[athlete].school;
                cout << left << setw(30) << athletes[athlete].score;

                cout << endl;
            }
        }
        cout << endl;
    }
}
