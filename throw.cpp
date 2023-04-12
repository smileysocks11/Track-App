#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void throwTurns(string athleteArray[], string* throwsArray, int flights, int athletes);

int main()
{

	string a[5] = { "Jeff", "Joe", "John", "Jacob", "Jack" };

	string* throwsArray = nullptr;
	//the numbers represent in the following order: althletes, rounds, flights
	throwsArray = new string[5 * 3 * 3];
	const int flights = 3;
	const int athletes = 5;
	throwTurns(a, throwsArray, flights, athletes);
}

void throwTurns(string athleteArray[], string* throwsArray, int flights, int athletes)
{
	/*use the loop to loop thorugh the array until all the athles from a single flight has
	the array is a 3D array where the first colum has the names of the students
	the second has the school they go to and the third has their best throw
	A failed attempt is a DQ in the stystem
	fill the first flight with more people than tht others if there are left*/

	int div = athletes / flights;
	char choice;
	int checkIndex = 0;
	string tossFt, tossIn, tossQtr;
	string measure;
	int tossCheck;
	bool scoreCheck = true;
	int name;


	int count = 0, amount = 0;
	int inFlights[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	if (div * flights != athletes)
	{
		for (int i = 0; i < flights; i++)
		{
			inFlights[i] += div;
		}

		int remainder = athletes - (div * flights);
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

	}
	else {
		for (int i = 0; i < flights; i++)
		{
			inFlights[i] += div;
		}
	}

	for (int i = 0; i < flights; i++)
	{
		cout << "\nThere will be " << inFlights[i] << " people in flight " << i + 1 << ".\n";
	}

	for (int f = 0; f < flights; f++)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int pass = 0; pass < inFlights[f]; pass++)
			{
				if (f > 0)
				{
					amount = 0;
					for (int i = 0; i < f; i++)
					{
						amount += inFlights[i];
					}
					name = amount + pass;
				}
				else
				{
					name = pass;
				}
				cout << "\nIs " << athleteArray[name] << " here to throw?\n(y/n)>";
				cin >> choice;
				while (choice != 'n' && choice != 'y')
				{
					cout << "Please enter y or n.\n(y/n)>";
					cin >> choice;
				}
				if (choice == 'y')
				{
					for (int i = 0; i < 3; i++)
					{
						if (i == 0)
						{
							measure = "feet";
							cout << "What is the distance of the athlete's throw for " << measure << "?\n>";
							cin.ignore();
							do
							{
								try
								{
									getline(cin, tossFt);
									tossCheck = stoi(tossFt);
									tossCheck = 0;
									scoreCheck = true;
								}
								catch (const std::exception&)
								{
									cout << "Please enter a numeric value.\n>";
									scoreCheck = false;
									tossFt.clear();
								}
							} while (scoreCheck == false);
							scoreCheck = true;
						}
						if (i == 1)
						{
							measure = "inches";
							cout << "What is the distance for the athlete's throw for " << measure << "?\n>";

							do
							{
								try
								{
									getline(cin, tossIn);
									tossCheck = stoi(tossIn);
									tossCheck = 0;
									scoreCheck = true;
								}
								catch (const std::exception&)
								{
									cout << "Please enter a numeric value.\n>";
									scoreCheck = false;
									tossIn.clear();
								}
							} while (scoreCheck == false);
							scoreCheck = true;
						}
						if (i == 2)
						{
							measure = "quater inches";
							cout << "What is the distance for the athlete's throw for " << measure << "?\n>";

							do
							{
								try
								{
									getline(cin, tossQtr);
									tossCheck = stoi(tossQtr);
									tossCheck = 0;
									scoreCheck = true;
								}
								catch (const std::exception&)
								{
									cout << "Please enter a numeric value.\n>";
									scoreCheck = false;
									tossQtr.clear();
								}
							} while (scoreCheck == false);
							scoreCheck = true;
						}
					}
					//add a throw to the array
					//format for enter the numbers into the array 105-2.5
					(throwsArray[name * r * f]) = tossFt + "-" + tossIn + "." + tossQtr;
					cout << (throwsArray[name * r * f]) << endl;
				}
				tossFt.clear();
				tossIn.clear();
				tossQtr.clear();
				//count++;
			}
		}
		count++;
	}
}

