#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Prototype functions
void updateFile(vector<string>);
void addAthlete();
void readFile();

// Temp function
int main()
{
	addAthlete();
}

/*--------------------------------
# addAthlete accepts no arguments
# it calls readFile() and scoreSort()
----------------------------------*/
void addAthlete()
{
	readFile();
	//getAthletes();
}

void readFile()
{
	ifstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\AthletesFile.txt)");
	vector<string> lines;
	string line;

	while (getline(athleteFile, line))
	{
		lines.push_back(line);
	}

	for (int i = 0; i < lines.size(); i++)
	{
		cout << lines[i] << endl;
	}

	athleteFile.close();

	updateFile(lines);

}

/*--------------------------------
# addAthlete accepts a string array
# It asks the name of the new athlete
# and adds it to the vector. It then
# writes the updated vector to the file
----------------------------------*/
void updateFile(vector<string> lines)
{
	// Variables and files
	ofstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\AthletesFile.txt)"); // Placeholder file
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
		// Loops as long as information is not entered in correctly
		while (tolower(confirm) == 'n')
		{
			// Takes input for first name
			cout << "\nEnter the first name of the athlete you would like to enter: ";
			getline(cin, newFirstname);

			// Takes input for last name
			cout << "Enter their last name: ";
			getline(cin, newLastname);

			// Takes input for max
			cout << "Enter their max (ie. 100-0): ";
			getline(cin, newMax);

			// Takes input for name of school
			cout << "Enter the name of their school: ";
			getline(cin, newSchool);

			// Loops through the tri-parallel arrays to rewrite them to the file
			for (int i = 0; i < lines.size(); i++)
			{
				athleteFile << lines[i] << endl;
			}

			// Outputs what user has entered and asks them if it is correct
			cout << "\nYou entered:\n"
				<< newFirstname << endl
				<< newLastname << endl
				<< newMax << endl
				<< newSchool << endl
				<< "Does this information look correct? (y/n): ";
			cin >> confirm;

			// Clears keyboard buffer if a repeat is neccessary
			if (confirm == 'n')
			{
				cin.ignore();
			}

			cout << endl;
		}

		// Writes the new athlete's information to the file
		athleteFile << newLastname << ", " << newFirstname << "#" << newMax << "#" << newSchool << endl;

		//readFile();

	}
	athleteFile.close();
}
