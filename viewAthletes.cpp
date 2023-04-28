// Carolyn Henderson
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Declare struct athleteInfo
struct athleteInfo
{
    string name, school, max, throw1, throw2, throw3, bestThrow;
    int flightNum;
    double bestDouble;
};

/*##########################
# viewAthletes accepts an array of athletes, the num of flights,
# and the number of athletes in the array
# It outputs all athletes in their separate flights
############################*/
void viewAthletes(athleteInfo athletes[], int flights, int numAthletes)
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

        // Loop through all athletes in the array
        for (athlete = 0; athlete < numAthletes; athlete++)
        {
            // Only output info if the athlete is in the current flight
            if (athletes[athlete].flightNum == flight + 1)
            {
                // Output information for the athlete
                cout << left << setw(25) << athletes[athlete].name;
                cout << left << setw(25) << athletes[athlete].school;
                cout << left << setw(25) << athletes[athlete].max;

                cout << endl;
            }
        }
        cout << endl;
    }
}
