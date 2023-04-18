#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct athleteInfo
{
    string name, school;
    double max, throw1, throw2, throw3, bestThrow;
    int flightNum;
};

/*##########################
# studLeaderboard accepts an array of all athletes
# and the number of athletes in the array
# It sorts students' info in order of best distance thrown
# It outputs the leaderboard to the user
############################*/
void studLeaderboard(athleteInfo athletes[], int numAthletes)
{
    // Initialize variables
    int counter = 0, feet = 0;
    float best = 0, inches = 0;
    athleteInfo tempAthlete;
    
    // Sort the array in descending order
    for (int maxElement = numAthletes - 1; maxElement > 0; maxElement--)
    {
        // Loop through the set area to check for anything out of order
        for (int index = 0; index < maxElement; index++)

            // Determine if the throws are in the right order
            if (athletes[index].bestThrow < athletes[index + 1].bestThrow)
            {
                // Swap athletes
                tempAthlete = athletes[index];
                athletes[index] = athletes[index + 1];
                athletes[index + 1] = tempAthlete;
            }
    }

    // Output the leaderboard
    for (int athlete = 0; athlete < numAthletes; athlete++)
    {
        // Determine how many feet are in the throw
        while (athletes[athlete].bestThrow - (12 * feet) >= 12)
            feet++;

        // Determine how many inches are in the throw
        inches = athletes[athlete].bestThrow - (12 * feet);

        // Output each piece of information for the athlete
        cout << setw(4) << athlete + 1 << left << setw(25) << athletes[athlete].name;
        cout << fixed << showpoint << setprecision(2) << feet << " ft " << inches << " in\t";
        cout << athletes[athlete].school << endl;

        // Reset variables
        feet = 0;
        inches = 0;
    }
}
