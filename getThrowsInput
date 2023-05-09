#include <iostream>
#include <string>
using namespace std;

int getThrowInput()
{
	// declares variables
	string input;
	int throws;
	bool throwsGood = false;

	do
	{
		cout << "How many throws is each athlete attempting? ";
		cin >> input;

		// Validate user input
		try
		{
			throws = stoi(input);

			// Make sure flights is greater than 0 and less than 5
			if (throws <= 0)
				throw invalid_argument("\nError: Enter a value greater than 0\n");
			if (throws > 4)
				throw invalid_argument("\nError: Enter a value less than or equal to 4\n");
			else
				throwsGood = true;
		}
		catch (exception)
		{
			cout << "\nError: Enter a numerical value greater than 0 for throws.\n";
			throwsGood = false;
		}

	} while (!throwsGood);

	return throws;
}
