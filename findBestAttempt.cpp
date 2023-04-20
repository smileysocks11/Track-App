#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct athleteInfo
{
	string name, school, max, throw1, throw2, throw3, bestThrow;
	int flightNum;
	double bestDouble;
};

/*############################
# findBestAttempt accepts an array with all athletes
# and the number of all athletes in the array
# It finds the best attempt for each student, and
# adds it to the array
##############################*/
void findBestAttempt(athleteInfo athletes[], int numAthletes)
{
	// Initialize variables and constants
	const int ROUNDS = 3;
	double reformAttempt, bestThrow = 0, inches = 0;
	string attempt, character, ftStr, inStr, bestStr;
	bool hitDash = false;
	int throwNum, indThrowNum = 1, athlete = 0;

	// Reformat throws to be doubles
	for (throwNum = 0; throwNum < (numAthletes * 3); throwNum++)
	{
		// Determine which attempt the loop reached
		switch (indThrowNum)
		{
		case 1: 
		{
			// Set the attempt & individual throw number
			attempt = athletes[athlete].throw1;
			indThrowNum = 2;
			break;
		}
		case 2: 
		{
			// Set the attempt & individual throw number
			attempt = athletes[athlete].throw2;
			indThrowNum = 3;
			break;
		}
		case 3: 
		{
			// Set the attempt & individual throw number
			attempt = athletes[athlete].throw3;
			indThrowNum = 1;

			// Put the best throw in the structure array and reset
			athletes[athlete].bestThrow = bestStr;
			athletes[athlete].bestDouble = bestThrow;
			bestThrow = 0;
			athlete++;
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
		cout << throwNum + 1 << " Best: " << bestStr << endl;
		inStr = ftStr = "";
		inches = 0;
		hitDash = false;
	}
}