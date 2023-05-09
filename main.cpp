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
void throwTurns(Athletes[], int, int, int);
void finals(Athletes[], int);
void studLeaderboard(Athletes[], int&);
void viewAthletes(Athletes[], int, int, bool);
void getFlights(Athletes[], int, string, int);
void addAthlete();
int getNumAthletes();
void manualAdjust(Athletes[], int&, int&);
void findBestAttempt(Athletes[], int&, int);
void finals(Athletes[], int);
bool athleteChecker(const Athletes& athlete);
int getFlightInput(int);
int getThrowInput();

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
	int flights, throws;
	bool throw_done = 0;
	string file_name, input;

	num_athletes = getNumAthletes();
	Athletes* athletes = nullptr;
	athletes = new Athletes[num_athletes];

	// calls scoreSort to sort the athletes in the file
	scoreSort(athletes, num_athletes);
	flights = getFlightInput(num_athletes);
	getFlights(athletes, num_athletes, input, flights);
	throws = getThrowInput();

	int choice = 0;

	// option constants
	int ADD = 1, THROW = 2, VIEW = 3, ADJUST = 4, QUIT = 5,  LB = 10, FINALS = 10, CHECK = 10;

	do
	{
		choice = displayMenu(choice, throw_done);
		cout << endl << endl;

		// add athlete option
		if (choice == ADD)
		{
			addAthlete();
			num_athletes = getNumAthletes();

			// resets structure array
			delete[] athletes;
			athletes = new Athletes[num_athletes];

			scoreSort(athletes, num_athletes);
			getFlights(athletes, num_athletes, input, flights);


		}
		// throw option
		else if (choice == THROW)
		{
			throwTurns(athletes, flights, num_athletes, throws);
			throw_done = 1;
			ADD = 10, THROW = 10, VIEW = 1, ADJUST = 10, QUIT = 5, LB = 2, FINALS = 3, CHECK = 4;
			findBestAttempt(athletes, num_athletes, throws);

		}
		//view althletes
		else if (choice == VIEW)
		{
			viewAthletes(athletes, flights, num_athletes, throw_done);
		}
		// manual adjust
		else if (choice == ADJUST)
		{
			viewAthletes(athletes, flights, num_athletes, throw_done);
			manualAdjust(athletes, num_athletes, flights);
		}

		// leaderboard
		else if (choice == LB)
			studLeaderboard(athletes, num_athletes);

		// finals
		else if (choice == FINALS)
			finals(athletes, num_athletes);

		// athlete checker
		else if (choice == CHECK)
		{ 
			int athlete_num = 0;
			bool isFinished;
			while (athlete_num != num_athletes) {

				Athletes athlete = athletes[athlete_num];

				isFinished = athleteChecker(athlete);

				athlete_num += 1;
			}
			cin.clear();
		}

		
		// quit
		else if (choice == QUIT)
		{
			cout << "Thank you for using Track App.\n";
		}



	} while (choice != QUIT);

	// clears memory
	delete[] athletes;

	return 0;
}
