#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void updateFile(string[], int);
void addAthlete();
void readFile();

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
	string arry[SIZE] = { "a b", "b c", "c d", "d e" };
	updateFile(arry, SIZE);
}

/*--------------------------------
# addAthlete accepts a string array
# It asks the name of the new athlete
# and adds it to the vector. It then
# writes the updated vector to the file
----------------------------------*/
void updateFile(string athleteArry[], int SIZE)
{
	// Variables and files
	ofstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\demoAthletes2.txt)"); // Placeholder file
	string newAthlete;
	string name;

	// Validates file
	if (!athleteFile)
	{
		cout << "File not found";
	}
	else
	{
		// Asks user for the name of the new athlete
		cout << "Enter the name of the athlete you would like to enter: ";
		getline(cin, newAthlete);

		// Loops through vector to write it to the file
		for (int i = 0; i < SIZE; i++)
		{
			athleteFile << athleteArry[i] << endl;
		}
		athleteFile << newAthlete << endl;

		readFile();

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
	ifstream athleteFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\demoAthletes2.txt)"); // Placeholder file
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
