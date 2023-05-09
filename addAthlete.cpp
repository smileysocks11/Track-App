#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Noah McGinley

bool validateString(string);

/*--------------------------------
# addAthlete accepts no arguments
# It asks the user for the new athlete's
# name, max, and school. It then appends
# the information to the athletes file
# matching the existing format
----------------------------------*/
void addAthlete()
{
	cin.ignore();

	// Placeholder file
	ofstream athleteFile("C:\\track_data\\raw-athletes.txt", ios_base::app);

	// Variables
	string newFirstname; // User inputed first name
	string newLastname; // User inputed last name
	string newMax; // User inputed max, will be -1 if there is no max
	string feet; // User inputed feet (for max)
	string inches; // User inputed inches (for max)
	string qtrInches; // User inputed quarter inches (for max)
	string displayNewMax; // Used to display max whwn outputed to user. This is to avoid displaying -1 if there is no max
	string newSchool; // User inputed school
	char ifMax; // Holds user input on whether or not the new athlete has a max
	char confirm = 'n'; // Holds user decision on whether or not to change information
	char addNewAthlete = 'y'; // Holds user decision on whetther or not to continue adding atheltes
	int inputCheck;
	bool check = true;

	// Validates file
	if (!athleteFile)
	{
		cout << "File not found";
	}
	else
	{

		while (tolower(addNewAthlete) == 'y') // repeats as long as user wants to continue adding athletes
		{
			confirm = 'n';

			// Loops if user wishes to change the information before confirming adding the athlete
			while (tolower(confirm) == 'n')
			{

				// Takes input for first name
				cout << "\nEnter the first name of the athlete you would like to add: ";
				getline(cin, newFirstname);
				while (newFirstname.empty())
				{
					cout << "Invalid input, re-enter the name: ";
					getline(cin, newFirstname);
				}

				// Takes input for last name
				cout << "Enter their last name: ";
				getline(cin, newLastname);
				while (newLastname.empty())
				{
					cout << "Invalid input, re-enter the name: ";
					getline(cin, newLastname);
				}

				// Takes input for max
				cout << "Do they have a max? (y/n): ";
				cin >> ifMax;
				while (!(tolower(ifMax) == 'y' || tolower(ifMax) == 'n'))
				{
					cout << R"(Invalid input. Enter either "y" or "n": )";
					cin >> ifMax;
				}
				cin.ignore();

				if (ifMax == 'y')
				{
					// Receives input for feet
					cout << "Enter their max.\n";
					cout << "For feet: ";
					getline(cin, feet);

					bool charValid = validateString(feet); // Validates that the string only contains digits

					while (!charValid || feet.empty())
					{
						cout << "Invalid input. Please enter a positive numeric value: ";
						getline(cin, feet);
						charValid = validateString(feet);
					}

					// -------------------------------
					// Receives input for inches
					cout << "For inches: ";
					getline(cin, inches);

					charValid = validateString(inches); // Validates that the string only contains digits
					bool numValid = false; // Validates if the value is within the correct range

					try
					{
						if (stoi(inches) <= 11)
						{
							numValid = true;
						}
						else
						{
							numValid = false;
						}
					}
					catch (exception) {};

					while (!charValid || !numValid)
					{
						cout << "Invalid input. Please enter a positive numeric value less than or equal to 11: ";
						getline(cin, inches);
						charValid = validateString(inches); // Validates that the string only contains digits

						try
						{
							if (stoi(inches) <= 11)
							{
								numValid = true;
							}
							else
							{
								numValid = false;
							}
						}
						catch (exception) {};
					}

					// ---------------------------------
					// Receives input for quarter inches
					cout << "For qtrInches: ";
					getline(cin, qtrInches);

					charValid = validateString(qtrInches);
					numValid = false;

					try
					{
						if (stoi(qtrInches) <= 3)
						{
							numValid = true;
						}
						else
						{
							numValid = false;
						}
					}
					catch (exception) {};

					while (!charValid || !numValid)
					{
						cout << "Invalid input. Please enter a positive numeric value less than or equal to 3: ";
						getline(cin, qtrInches);
						charValid = validateString(qtrInches);

						try
						{
							if (stoi(qtrInches) <= 3)
							{
								numValid = true;
							}
							else
							{
								numValid = false;
							}
						}
						catch (exception) {};
					}

					// ------------------------------------

					newMax = feet + "-" + inches + "." + qtrInches;
					displayNewMax = newMax;

				}
				else
				{
					newMax = "-1";
					displayNewMax = "No max";
				}

				// Takes input for name of school
				cout << "Enter the name of their school: ";
				getline(cin, newSchool);

				// Outputs what user has entered and asks them if it is correct
				cout << "\nYou entered:\n"
					<< "First name: " << newFirstname << endl
					<< "Last name: " << newLastname << endl
					<< "Max: " << displayNewMax << endl
					<< "School: " << newSchool << endl
					<< "Does this information look correct? (y/n): ";
				cin >> confirm;
				while (!(tolower(confirm) == 'y' || tolower(confirm) == 'n'))
				{
					cout << R"(Invalid input. Enter either "y" or "n": )";
					cin >> confirm;
				}

				// Clears keyboard buffer if a repeat is neccessary
				if (tolower(confirm) == 'n')
				{
					cin.ignore();
				}
			}

			// Writes the new athlete's information to the file
			athleteFile << endl << newLastname << ", " << newFirstname << "#" << newMax << "#" << newSchool;

			cout << "Athlete added.\n";

			// Asks user if they would like to continue adding additional athletes
			cout << "Would you like to continue adding additional athletes? (y/n): ";
			cin >> addNewAthlete;
			while (!(tolower(addNewAthlete) == 'y' || tolower(addNewAthlete) == 'n'))
			{
				cout << R"(Invalid input. Enter either "y" or "n": )";
				cin >> addNewAthlete;
			}

			// Clears keyboard buffer if a repeat is neccessary
			if (tolower(addNewAthlete) == 'y')
			{
				cin.ignore();
			}

		}
	}
	// Closes file
	athleteFile.close();
}


/*-------------------------------
# accepts a string as input
# It checks to see if the string only contains digits
---------------------------------*/
bool validateString(string input)
{
	return input.find_first_not_of("0123456789") == string::npos;
}
