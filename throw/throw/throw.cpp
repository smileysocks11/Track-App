#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

//Landon Marcotte

struct Athletes
{
	string name;
	string school;
	string max;
	string throw1, throw2, throw3;
	string bestThrow;
	int flightNum;
};

void throwTurns(Athletes* a, int flights, int athletes);

int main()
{
	int at = 5;

	Athletes* ar = nullptr;
	ar = new Athletes[at];
	ar[0].name = "Jeff";
	ar[1].name = "Joe";
	string a[5] =  {"Jeff", "Joe", "John", "Jacob", "Jack"};

	string* throwsArray = nullptr;
	//the numbers represent in the following order: althletes, rounds, flights
	throwsArray = new string[5 * 3 * 3];
	const int flights = 3;
	throwTurns(ar, flights, at);
}

void throwTurns(Athletes* a, int flights, int athletes)
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


	int count = 0, amount = 0;
	int inFlights[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
	
	for (int i = 0; i < flights; i++)
	{
		cout << "\nThere will be " << inFlights[i] << " people in flight " << i + 1 << ".\n";
	}


	for (int f = 0; f < flights; f++)
	{
		for (int r = 0; r < 3; r++)
		{
			count = amount;
			for (int i = 0; i < inFlights[f]; i++)
			{
				
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