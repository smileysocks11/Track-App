#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <python.h>
#include <windows.h>
#include "Athletes.h"
using namespace std;


// function prototypes
int displayMenu(int, bool);
void scoreSort(Athletes[], int&);
void throwTurns(Athletes[], int, int);
void finals(Athletes[], int);
void studLeaderboard(Athletes[], int);
void viewAthletes(Athletes[], int, int);
int getFlights(Athletes[], int&);
void addAthlete();
int getNumAthletes();

int main()
{
	// repository creator
	wstring filePath = L"C:\\track_data";
	LPCWSTR path = filePath.c_str();

	// python
	const char* argv[2];
	argv[0] = "C:\\track_data\\webscrape.py";

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
	bool throw_done = 0;
	string file_name;

	num_athletes = getNumAthletes();
	Athletes* athletes = nullptr;
	athletes = new Athletes[num_athletes];

	// calls scoreSort to sort the athletes in the file
	scoreSort(athletes, num_athletes);

	// calls getFlights to get the number of flights from the user
	flights = getFlights(athletes, num_athletes);

	int choice = 0;

	do
	{
		choice = displayMenu(choice, throw_done);
		cout << endl << endl;

		// add athlete option
		if (choice == 1)
		{
			// adds athlete
			addAthlete();
			num_athletes = getNumAthletes();
			scoreSort(athletes, num_athletes);


		}
		// throw option
		else if (choice == 2)
		{
			for (int i = 0; i < num_athletes; i++)
				// runs the throws
				throwTurns(athletes, flights, num_athletes);
		}
		//view althletes
		else if (choice == 3)
		{
			viewAthletes(athletes, flights, num_athletes);
		}



	} while (choice != 6);

	// clears memory
	delete[] athletes;

	return 0;
}
