// Carolyn Henderson
#include <iostream>
#include <string>
#include <vector>
#include "Athletes.h"
using namespace std;

// Declare structure


/*############################
# findBestAttempt accepts an array with all athletes
# and the number of all athletes in the array
# It finds the best attempt for each student, and
# adds it to the array
##############################*/
void findBestAttempt(Athletes athletes[], int& numAthletes, int throws)
{
	// Initialize variables and constants
	double reformAttempt, bestThrow = 0, inches = 0;
	string attempt, character, ftStr, inStr, bestStr;
	bool hitDash = false;
	int throwNum, athlete;

	// Reformat throws to be doubles
	for (athlete = 0; athlete < numAthletes; athlete++)
	{
		for (throwNum = 0; throwNum < throws; throwNum++)
		{
			// Determine which attempt the loop reached
			switch (throwNum)
			{
			case 0:
			{
				// Set the attempt & individual throw number
				attempt = athletes[athlete].throw1;
				break;
			}
			case 1:
			{
				// Set the attempt & individual throw number
				attempt = athletes[athlete].throw2;
				break;
			}
			case 2:
			{
				// Set the attempt & individual throw number
				attempt = athletes[athlete].throw3;
				break;
			}
			case 3:
			{
				// Set the attempt & individual throw number
				attempt = athletes[athlete].throw4;
				break;
			}
			default: cout << "Error: Invalid throw num\n\n";
			}

			// Loop through the characters in the throw
			for (auto character : attempt)
			{
				// Determine if dash has been hit yet
				if (character == '-')
					hitDash = true;

				// Num of feet is the num before the dash
				if (!hitDash)
					ftStr += character;
				else
				{
					// If current character is not dash, add to inches
					if (character != '-')
						inStr += character;
				}
			}

			// Determine inches
			try
			{
				inches = (stod(ftStr) * 12) + stod(inStr);
			}
			catch (exception)
			{
				cout << "Error: Can't convert to double\n";
			}

			// Determine if the attempt is best for the athlete so far
			if (inches > bestThrow)
			{
				bestThrow = inches;
				bestStr = attempt;
			}

			// Reset variables
			inStr = ftStr = "";
			inches = 0;
			hitDash = false;
		}

		// Set the athlete's best attempt
		athletes[athlete].bestThrow = bestStr;
		athletes[athlete].bestDouble = bestThrow;
		bestThrow = 0;
	}
}
