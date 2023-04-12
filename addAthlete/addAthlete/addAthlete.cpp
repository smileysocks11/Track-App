#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Prototype functions
void updateFile(string[], string[], string[], int);
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
	const int SIZE = 4;
	string name[SIZE] = { "a b", "b c", "c d", "d e" };
	string max[SIZE] = { "10-1", "11-2", "12-3", "13-4" };
	string school[SIZE] = { "w", "x", "y", "z" };
	updateFile(name, max, school, SIZE);
}

/*--------------------------------
# addAthlete accepts a string array
# It asks the name of the new athlete
# and adds it to the vector. It then
# writes the updated vector to the file
----------------------------------*/
void updateFile(string name[], string max[], string school[], int SIZE)
{
	// Variables and files
	ofstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\AthletesFile.txt)"); // Placeholder file
	string newFirstname;
	string newLastname;
	string newMax;
	string newSchool;

	// Validates file
	if (!athleteFile)
	{
		cout << "File not found";
	}
	else
	{
		// Takes input for first name
		cout << "Enter the first name of the athlete you would like to enter: ";
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
		for (int i = 0; i < SIZE; i++)
		{
			athleteFile << name[i] << "#" << max[i] << "#" << school[i] << endl;
		}

		// Writes the new athlete's information to the file
		athleteFile << newLastname << ", " << newFirstname << "#" << newMax << "#" << newSchool << endl;

		//readFile();

	}
	athleteFile.close();
}

/*--------------------------------
# readFile accepts no arguments
# It opens the file of athletes
# and puts the names into a vector
----------------------------------*/
void readFile()
{
	// Variables and files
	ifstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\AthletesFile.txt)"); // Placeholder file
	vector<string> nameList;
	string name;
	string newAthlete;
	int i = 0;

	// Validates file
	if (!athleteFile)
	{
		cout << "File not found.\n";
	}
	else
	{
		// Reads file to add to vector
		while (getline(athleteFile, name))
		{
			nameList.push_back(name);
			i++;
		}

		for (int i = 0; i < nameList.size(); i++)
		{
			cout << nameList[0] << endl;
		}
	}
	athleteFile.close();

}
