#include <iostream>
#include <string>
using namespace std;

int getFlightInput(int num_athletes)
{

	// declares variables
	string input;
	int flights;
	bool flightGood = false, retry = false;

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

	return flights;
}
