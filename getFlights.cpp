/*
 * BRIGHTON HILYARD'S FILE
*/

#include <iostream>
#include <string>
#include "Athletes.h"
using namespace std;



int getFlights(Athletes a[], int num_athletes) {
	/*
	 * gets the amount of flights for the meet
	 * returns to main
	 */
	string input;
	int flights = 0;
	bool flightGood = false, retry = false;

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

	int count = 0;
	int div = num_athletes / flights;
	int inFlights[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	if (div * flights != num_athletes)
	{
		for (int i = 0; i < flights; i++)
		{
			inFlights[i] += div;
		}

		int remainder = num_athletes - (div * flights);
		while (remainder != 0)
		{
			inFlights[count] += 1; remainder -= 1;
			count++;
			if (count == flights)
			{
				count = 0;
			}
		}
		count = 0;

		for (int f = 0; f < 10; f++)
		{
			for (int i = 0; i < inFlights[f]; i++)
			{
				a[count].flightNum = f + 1;
				count++;
			}
		}
		count = 0;
	}
	else {
		for (int i = 0; i < flights; i++)
		{
			inFlights[i] += div;
		}
		for (int f = 0; f < 10; f++)
		{
			for (int i = 0; i < inFlights[f]; i++)
			{
				a[count].flightNum = f + 1;
				count++;
			}
		}
		count = 0;
	}

	return flights;
}
