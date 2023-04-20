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
# studLeaderboard accepts an array of all athletes
# and the number of athletes in the array
# It sorts students' info in order of best distance thrown
# It outputs the leaderboard to the user
############################*/
void studLeaderboard(athleteInfo athletes[], int numAthletes)
{
    // Initialize variables
    int counter = 0;
    float best = 0;
    athleteInfo tempAthlete;

    // Sort the array in descending order
    for (int maxElement = numAthletes - 1; maxElement > 0; maxElement--)
    {
        // Loop through the set area to check for anything out of order
        for (int index = 0; index < maxElement; index++)
        {
            try
            {
                // Determine if the throws are in the right order
                if (athletes[index].bestDouble < athletes[index + 1].bestDouble)
                {
                    // Swap athletes
                    tempAthlete = athletes[index];
                    athletes[index] = athletes[index + 1];
                    athletes[index + 1] = tempAthlete;
                }
            }
            catch (exception)
            {
                cout << athletes[index].bestThrow << endl;
                cout << "Error converting stod\n\n";
            }
        }
    }

    // Output the leaderboard
    for (int athlete = 0; athlete < numAthletes; athlete++)
    {
        // Output each piece of information for the athlete
        cout << left << setw(4) << athlete + 1 << setw(25) << athletes[athlete].name;
        cout << athletes[athlete].school << "\t" << athletes[athlete].bestThrow << endl;
    }
}
