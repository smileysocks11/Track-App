#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// function prototypes
void viewAthletes(string(*athletes)[3][3], int);
void getAthletes(vector<string>, string*, string*, double*);
int displayMenu(int choice);


int main()
{
	// declares variables
	vector<string> lines;
	string line;
	int num_athletes;

	// opens the file
	ifstream in_file("C:\\Users\\SSC00042\\Desktop\\data_files\\athlete-database.txt");

	// loops to read through each line in the file
	// adds each line to the vector
	int index = 0;
	while (getline(in_file, line))
	{
		lines.push_back(line);
		index++;
	}
	
	num_athletes = lines.size();
	
	// creates three pointer arrays for name, school, and max
	// based on the size of the student vector
	string* name = nullptr;
	name = new string[num_athletes];
	string* school = nullptr;
	school = new string[num_athletes];
	double* max = nullptr;
	max = new double[num_athletes];

	// calls getAthletes to input all of the athletes
	// into a tri-parallel array
	getAthletes(lines, name, school, max);

	/* 
	// menu stuff
	int choice = 0;

	do
	{
		int choice = displayMenu();
		cout << endl << endl;

		if (choice == 1)
			


	} while (choice != 6);

	*/
	// deletes the pointer arrays
	delete[] name;
	name = nullptr;
	delete[] school;
	school = nullptr;
	delete[] max;
	max = nullptr;

	in_file.close();
	return 0;


	// string* ThrowsAway = nullptr;
	// ThrowsAway = new string[athletes * num_athletes * flights]
}