#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*--------------------------------
# addAthlete accepts no arguments
# It asks the user for the new athlete's
# name, max, and school. It then appends
# the information to the athletes file
# matching the existing format
----------------------------------*/
void addAthlete()
{
	// Variables and files
	ofstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\AthletesFile.txt)", ios_base::app); // Placeholder file
	string newFirstname;
	string newLastname;
	string newMax;
	string newSchool;
	char confirm = 'n';

	// Validates file
	if (!athleteFile)
	{
		cout << "File not found";
	}
	else
	{
		while (tolower(confirm) == 'n')
		{
			// Takes input for first name
			cout << "\nEnter the first name of the athlete you would like to add: ";
			getline(cin, newFirstname);

			// Takes input for last name
			cout << "Enter their last name: ";
			getline(cin, newLastname);

			// Takes input for max
			cout << "Enter their max (ie. 100-0.0). Enter -1 if they do not have a max: ";
			getline(cin, newMax);

			// Takes input for name of school
			cout << "Enter the name of their school: ";
			getline(cin, newSchool);

			// Outputs what user has entered and asks them if it is correct
			cout << "\nYou entered:\n"
				<< newFirstname << endl
				<< newLastname << endl
				<< newMax << endl
				<< newSchool << endl
				<< "Does this information look correct? (y/n): ";
			cin >> confirm;

			// Clears keyboard buffer if a repeat is neccessary
			if (tolower(confirm) == 'n')
			{
				cin.ignore();
			}
		}

		// Writes the new athlete's information to the file
		athleteFile << newLastname << ", " << newFirstname << "#" << newMax << "#" << newSchool << endl;

		// Closes file
		athleteFile.close();
	}
}
