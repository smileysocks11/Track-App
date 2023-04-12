/*#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
-------------------------------
- getAthletes accepts no arguments
- retrieves the athletes from a file
- inserts them in a tri-parallel array
- returns the tri-parallel array
-------------------------------
*/
/*
void getAthletes(vector<string> lines, string* name, string* school, double* max)
{
	// declares variables
	string line, type = "name";
	vector<string> sep;
	int sep_count = 0;
	int size = lines.size();


	// loops through all of the students in the vector
	for (int index = 0; index < size; index++)
	{
		// splits string
		line = lines[index];
		stringstream ss(line);

		while (ss.good())
		{
			string substr;
			getline(ss, substr, '#');
			sep.push_back(substr);
		}

	}

	// loops through the vector to add each type to the designated array
	for (int index = 0; index < size; index++)
	{
		name[index] = sep[sep_count];
		sep_count++;
		double temp_max = stod(sep[sep_count]);
		max[index] = temp_max;
		sep_count++;
		school[index] = sep[sep_count];
		sep_count++;
	}


}
*/