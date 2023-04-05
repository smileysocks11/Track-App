#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

/*##########################
# studLeaderboard accepts a float array with 3 attempts
# from each athlete, 2 string arrays for the names and
# schools of each athlete, and the num of flights and athletes
# It sorts students' info in order of best distance thrown
# It outputs the leaderboard to the user
############################*/
void studLeaderboard(float attempts[][3], string names[], string schools[], int flights, int numAthletes)
{
    // Initialize variables
    const int NUM_ATHLETES = numAthletes;
    int counter = 0, feet = 0;
    float tempFloat, best = 0, inches = 0;
    string tempString;
    vector<float> bestThrows(numAthletes);

    // Populate bestThrows using attempts
    for (int athlete = 0; athlete < numAthletes; athlete++)
    {
        // Loop through all throws the athlete made
        for (int attempt = 0; attempt < 3; attempt++)
        {
            // Determine if the throw is the best the athlete made
            if (attempts[athlete][attempt] > best)
            {
                best = attempts[athlete][attempt];
            }
        }

        // Put the athlete's best attempt into bestThrows and reset
        bestThrows[athlete] = best;
        best = 0;
    }

    // Sort the 3 vectors in descending order
    for (int maxElement = numAthletes - 1; maxElement > 0; maxElement--)
    {
        // Loop through the set area to check for anything out of order
        for (int index = 0; index < maxElement; index++)

            // Determine if the throws are in the right order
            if (bestThrows[index] < bestThrows[index + 1])
            {
                // Swap best throws
                tempFloat = bestThrows[index];
                bestThrows[index] = bestThrows[index + 1];
                bestThrows[index + 1] = tempFloat;

                // Swap names
                tempString = *(names + index);
                *(names + index) = *(names + index + 1);
                *(names + index + 1) = tempString;

                // Swap schools
                tempString = *(names + index);
                *(names + index) = *(names + index + 1);
                *(names + index + 1) = tempString;
            }
    }

    // Output the leaderboard
    for (int athlete = 0; athlete < numAthletes; athlete++)
    {
        // Determine how many feet are in the throw
        while (bestThrows[athlete] - (12 * feet) >= 12)
            feet++;

        // Determine how many inches are in the throw
        inches = bestThrows[athlete] - (12 * feet);

        // Output each piece of information for the athlete
        cout << setw(4) << athlete + 1 << left << setw(25) << names[athlete];
        cout << fixed << showpoint << setprecision(2) << feet << " ft " << inches << " in\t";
        cout << schools[athlete] << endl;

        // Reset variables
        feet = 0;
        inches = 0;
    }
}