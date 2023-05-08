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
void studLeaderboard(Athletes[], int&);
void viewAthletes(Athletes[], int, int, bool);
void getFlights(Athletes[], int, string, int);
void addAthlete();
int getNumAthletes();
void manualAdjust(Athletes[], int&, int&);
void findBestAttempt(Athletes[], int&);
void finals(Athletes[], int);
bool athleteChecker(const Athletes& athlete);

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
	string file_name, input;
	bool flightGood = false, retry = false;

	num_athletes = getNumAthletes();
	Athletes* athletes = nullptr;
	athletes = new Athletes[num_athletes];

	// calls scoreSort to sort the athletes in the file
	scoreSort(athletes, num_athletes);

	// calls getFlights to get the number of flights from the user
	// Loop until flights is good
	do
	{
		cout << "\nThere are " << num_athletes << " athletes attending the meet.\n";
		cout << "How any flights would you like in this meet? ";
		cin >> input;

		// Validate user input
		try
		{
			flights = stoi(input);

			// Make sure flights is greater than 0
			if (flights <= 0)
				throw invalid_argument("\nError: Enter a value greater than 0\n");

			// Loop until the user enters y or n
			do
			{
				// Make sure the number is good
				cout << "With " << flights << " flights, there will be about " << num_athletes / flights
					<< " athletes per flight. Is this number appropriate? (y/n)\n> ";
				cin >> input;

				// Validate user input
				if (input == "y" || input == "Y")
				{
					flightGood = true;
					retry = true;
				}
				else if (input == "n" || input == "N")
				{
					flightGood = false;
					cout << "Reenter number for flights:\n";
					retry = true;
				}
				else
				{
					cout << "\nError: Please enter y or n\n\n";
					retry = false;
				}
			} while (!retry);

		}
		catch (exception)
		{
			cout << "\nError: Enter a numerical value greater than 0 for flights\n";
			flightGood = false;
		}

	} while (!flightGood);
	getFlights(athletes, num_athletes, input, flights);

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
			throwTurns(athletes, flights, num_athletes);
			throw_done = 1;
			ADD = 10, THROW = 10, VIEW = 1, ADJUST = 10, QUIT = 5, LB = 2, FINALS = 3, CHECK = 4;
			findBestAttempt(athletes, num_athletes);

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
