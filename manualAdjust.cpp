#include <iostream> // BY NOAH JACKSON
#include <string>
#include <cctype>
#include <limits>
#include "Athletes.h"
using namespace std;

/*int main() >>>> USED FOR EXAMPLES
{

	athletes a[3];

	a[0].name = "John";
	a[0].flightNum = 1;

	a[1].name = "Joe";
	a[1].flightNum = 1;

	a[2].name = "Kyle";
	a[2].flightNum = 1;

	manualAdjust(a, 3, 5);

	cout << a[0].name << endl << endl;
	cout << a[0].flightNum << endl << endl;

	cout << a[1].name << endl << endl;
	cout << a[1].flightNum << endl << endl;

	cout << a[2].name << endl << endl;
	cout << a[2].flightNum << endl << endl;

}*/

/*#########################################
manualAdjust accepts a structure list, <- its
size, and the total amount of flights.
It's going to ask the user if they want to
move an athlete to another flight, if so,
ask for the name and the flight and then change
the athlete's flight number (flightNum).
*///######################################
void manualAdjust(Athletes allAthletes[], int& totalAthletes, int& totalFlights)
{

	// initialize variables
	string athlete; // athlete's name
	string fullName; // the first and last name of the athlete (used for formatting)
	int index; // used for formatting (finds the index of the space)
	int count;
	bool found; // for whether the athlete's name is valid or not
	char response = 'y'; // if the user would like to move another athlete
	int athleteIndex; // athlete's index in the structure array
	int flight; // the flight that the athlete is being moved to
	char flightString[3]; // used for validating the flight number
	
	// this change was made for the buffer
	cin.ignore();
	
	// loop until the user no longer wants to move athletes
	while (response == 'y')
	{

		// reset / set variables
		found = false;
		flight = -1;
		athlete = "";

		// loop until a valid name is entered
		while (!found)
		{
			// ask the user for the athletes name
			cout << "\nEnter the name of the athlete you'd like to move (FirstName LastName): ";
			getline(cin, fullName);

			int fullNameLength = (int)fullName.length() + 2;  // + 2 for '\0' and ','
			char* newString = new char[fullNameLength];

			int spaceIndex = (int)fullName.find(" "); // (int) to be interpretted as integer

			int j = 0;
			for (int i = spaceIndex + 1; i < fullNameLength - 2 && j < fullNameLength; i++)
			{
				newString[j++] = fullName[i];
			}

			if (j < fullNameLength)
				newString[j++] = ',';
			if (j < fullNameLength)
				newString[j++] = ' ';

			for (int i = 0; i < spaceIndex && i < fullNameLength - 1; i++)
			{
				newString[j++] = fullName[i];
			}

			if (j <= fullNameLength - 1)
				newString[j] = '\0'; // manually put in the null terminator

			// convert the character string array to a std::string
			string newName(newString);

			// loop to check for that athlete in the flights
			for (count = 0; count < totalAthletes; count++)
			{

				// compare the names 
				if (newName == allAthletes[count].name)
				{
					found = true;
					athleteIndex = count;
					break;
				}

			}

			// if the name doesn't match any other names, tell the user
			if (!found)
				cout << endl << fullName << " was not found in any of the flights.\n";

			delete[] newString;// free up the memory

		}

		// loop until the user enters a valid flight number
		while (flight < 1 || flight > totalFlights)
		{
			// ask the user for a flight number
			cout << "\nEnter the flight number that you'd like to move " << fullName << " to: ";
			cin.getline(flightString, 3, '\n');

			if (cin.fail())
			{
				// tell the user off
				cout << "\nPlease enter reasonable characters.\n";

				// clear the stream
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			// try statement for when the user enters less than three non digit characters
			try {
				// change the character string to an integer
				flight = stoi(flightString);
			}
			catch (exception) {
				cout << "\nPlease enter reasonable character.\n";
				continue;
			}

			// validate the flight number
			if (flight < 1 || flight > totalFlights)
				cout << "\nThe flight number you entered is not valid.\n";

		}

		// after both requirements are met, switch the user to another flight
		allAthletes[athleteIndex].flightNum = flight;
		cout << "\n" << fullName << " was successfully moved to flight " << flight << endl;

		// ask the user if they would like to move another athlete
		cout << "\nWould you like to move another athlete? (y/n): ";
		cin >> response;
		response = tolower(response);

		// ignore the white space key that was pressed
		cin.ignore();

	}

}
