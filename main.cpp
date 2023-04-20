#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <python.h>
using namespace std;

// function prototypes
void getAthletes(vector<string>, string*, string*, double*);
int displayMenu(int, bool);
void scoreSort();
vector<string> readFile(string);
void throwTurns(string[], string*, int, int);
void studLeaderboard(string*, string[], string[], int, int);
void viewAthletes(string*, string*, double*, int);
int getFlights(int);

/*
readFile accepts no arguments
- reads the lines from a given file
- outputs the vector of lines
*/
vector<string> readFile(string file_name)
{
	// declares variables
	vector<string> lines;
	string line;

	// opens the file
	ifstream in_file(file_name);

	// loops to read through each line in the file
	// adds each line to the vector
	int index = 0;
	while (getline(in_file, line))
	{
		lines.push_back(line);
		index++;
	}

	// closes the file
	in_file.close();

	return lines;
}

int main()
{

	// python
	const char* argv[2];
	argv[0] = "C:\\Users\\SSC00042\\Desktop\\webscrape.py";

	Py_Initialize();
	PyObject* obj = Py_BuildValue("s", argv[0]);
	FILE* file = _Py_fopen_obj(obj, "r");
	if (file)
		PyRun_SimpleFile(file, argv[0]);
	Py_Finalize();


	// declares variables
	vector<string> lines;
	int num_athletes;
	int flights;
	const int rounds = 3;
	string* throwsArray = nullptr;
	bool throw_done = 0;
	string file_name;

	// gets the lines from the file from readFile
	file_name = "C:\\Users\\SSC00042\\Desktop\\raw-athlete-database.txt";
	lines = readFile(file_name);

	// creates three pointer arrays for name, school, and max
	// based on the size of the student vector
	string* name = nullptr;
	name = new string[lines.size()];
	string* school = nullptr;
	school = new string[lines.size()];
	double* max = nullptr;
	max = new double[lines.size()];

	// calls getAthletes to input all of the athletes
	// into a tri-parallel array
	getAthletes(lines, name, school, max);

	// calls scoreSort to sort the athletes in the file
	scoreSort();

	// calls getAthletes again to get the sorted athletes
	// and put them into a tri-parallel array
	file_name = "C:\\Users\\SSC00042\\Desktop\\sorted-athlete-database.txt";
	lines = readFile(file_name);
	num_athletes = lines.size();

	// calls getFlights to get the number of flights from the user
	flights = getFlights(num_athletes);
	throwsArray = new string[num_athletes * rounds * flights];
	getAthletes(lines, name, school, max);

	int choice = 0;

	do
	{
		choice = displayMenu(choice, throw_done);
		cout << endl << endl;

		// throw option
		if (choice == 1)
		{
			throwTurns(name, throwsArray, flights, num_athletes);
			throw_done = 1;

		}
		/* view leaderboard option
		else if (choice == 2)
		{
			if (throw_done == 0)
				"\nNo student has thrown.\n";
			else
				studLeaderboard(throwsArray, name, school, flights, num_athletes);
		}
		*/




	} while (choice != 6);

	// deletes the pointer arrays
	delete[] name;
	name = nullptr;
	delete[] school;
	school = nullptr;
	delete[] max;
	max = nullptr;
	return 0;

	// string* ThrowsAway = nullptr;
	// ThrowsAway = new string[athletes * num_athletes * flights]
}
