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
void viewAthletes(Athletes athletes[], int flights, int numAthletes, bool throw_done)
{
    // Initialize variables
    int flight, athlete;

    // Loop through all flights
    for (flight = 0; flight < flights; flight++)
    {
        // Output the flight number
        cout << "Flight " << flight + 1 << ": \n";

        // Output heading
        cout << left << setw(35) << "Name"
            << left << setw(35) << "School"
            << left << setw(35) << "High Score" << endl;
        cout << "---------------------------------------------------------------------------------\n";

        // Loop through all athletes in the array
        for (athlete = 0; athlete < numAthletes; athlete++)
        {
            // Only output info if the athlete is in the current flight
            if (athletes[athlete].flightNum == flight + 1)
            {
                // Output information for the athlete
                cout << left << setw(35) << athletes[athlete].name;
                cout << left << setw(35) << athletes[athlete].school;

                if (throw_done == 0)
                    cout << left << setw(35) << athletes[athlete].score;
                else
                    cout << left << setw(35) << athletes[athlete].bestThrow;

                cout << endl;
            }
        }
        cout << endl;
    }
}
