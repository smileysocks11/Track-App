#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include "Athletes.h"
using namespace std;

//Landon Marcotte


void finals(Athletes a[], int athletes);

void finals(Athletes a[], int athletes)
{
	//variables for holding the best throws
	double tempF = 0, tempI = 0, tempQ = 0, tempTotal = 0;
	double b[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, at[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int count = 0;
	string temp;
	bool check = false;
	char choice;
	int tossCheck;
	string measure;
	bool scoreCheck = true;
	string tossFt, tossIn, tossQtr;

	for (int i = 0; i < athletes; i++)
	{
		count = 0;
		tempF = stod(a[i].bestThrow);
		do
		{
			count++;
			if (a[i].bestThrow[count] == '-')
			{
				check = true;
			}
		} while (check == false);
		check = false;
		count++;
		do
		{
			temp += a[i].bestThrow[count];
			count++;
		} while (a[i].bestThrow[count] != '.');
		tempI = stod(temp);
		temp.clear();
		count++;
		do
		{
			temp += a[i].bestThrow[count];
			count++;
		} while (a[i].bestThrow[count] != '\0');
		tempQ = stod(temp);
		temp.clear();

		cout << tempF << " " << tempI << " " << tempQ << endl;
		tempTotal = tempF + ((tempI + (tempQ * .25)) / 12);
		tempF = 0;
		tempI = 0;
		tempQ = 0;

		count = 7;
		do
		{
			if (tempTotal > b[count])
			{
				int amount = count;
				while (count != 0)
				{
					b[amount - count] = b[amount - count + 1];
					at[amount - count] = at[amount - count + 1];
					count--;
				}
				b[amount] = tempTotal;
				at[amount] = i;
			}
			count--;
		} while (count > -1 && tempTotal != b[count]);
	}
	count = 0;
	for (int r = 0; r < 3; r++)
	{
		count = 0;
		for (int i = 0; i < 8; i++)
		{
			//might need to make an integer
			int index = at[i];
			cout << index << endl;
			cout << "Round " << r + 1 << endl << endl;
			cout << "\nIs " << a[index].name << " here to throw?\n(y/n)>";
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
					a[index].throw1 = tossFt + "-" + tossIn + "." + tossQtr;
				}
				if (r == 1)
				{
					a[index].throw2 = tossFt + "-" + tossIn + "." + tossQtr;
				}
				if (r == 2)
				{
					a[index].throw3 = tossFt + "-" + tossIn + "." + tossQtr;
				}
			}
			tossFt.clear();
			tossIn.clear();
			tossQtr.clear();
		}
	}
}