#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Athletes.h"
using namespace std;

//Landon Marcotte



void throwTurns(Athletes a[], int flights, int athletes, int rounds);

void throwTurns(Athletes a[], int flights, int athletes, int rounds)
{
	/*use the loop to loop through the array until all the athletes from a single flight has
	thrown and moves on to the next athletes in the structure bassed off their throw
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


	int count = 0, amount = 0;
	int inFlights[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	for (size_t i = 0; i < flights; i++)
	{
		while (a->flightNum == count)
		{
			inFlights[count]++;
		}
	}
	count = 0;

	for (int f = 0; f < flights; f++)
	{
		for (int r = 0; r < rounds; r++)
		{
			count = amount;
			for (int i = 0; i < inFlights[f]; i++)
			{
				cout << "Flight " << f + 1 << endl << endl;
				cout << "Round " << r + 1 << endl << endl;
				cout << "\nIs " << a[count].name << " here to throw?\n(y/n)>";
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
					if (r == 0)
					{
						a[count].throw1 = tossFt + "-" + tossIn + "." + tossQtr;
					}
					if (r == 1)
					{
						a[count].throw2 = tossFt + "-" + tossIn + "." + tossQtr;
					}
					if (r == 2)
					{
						a[count].throw3 = tossFt + "-" + tossIn + "." + tossQtr;
					}
					cout << a[count].throw1 << endl;
				}
				tossFt.clear();
				tossIn.clear();
				tossQtr.clear();
				count++;
			}
		}
		amount += inFlights[f];
	}
}

