#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ATHLETES = 100; // Maximum number of athletes that can be read from the input file

struct Athletes {
    string name;
    string score;
    string school;
    double feet;
    double inches;
};

// declares functions
void swapAthletes(Athletes&, Athletes&);
void sortAthletes(Athletes[], int);

// Swaps the values of two Athlete variables
void swapAthletes(Athletes& a, Athletes& b) {
    Athletes temp = a;
    a = b;
    b = temp;
}

// Sorts the array of Athletes in ascending order of score using bubble sort
void sortAthletes(Athletes athletes[], int numAthletes) {
    for (int i = 0; i < numAthletes - 1; i++) {
        for (int j = 0; j < numAthletes - i - 1; j++) {
            if (athletes[j].feet > athletes[j + 1].feet && athletes[j].score != "-1")
                swapAthletes(athletes[j], athletes[j + 1]);
            else if (athletes[j].inches > athletes[j + 1].inches)
                swapAthletes(athletes[j], athletes[j + 1]);
        }
    }
}

void scoreSort(Athletes* athletes) {

    ifstream inputFile("C:\\track_data\\raw-athletes.txt"); // Open the input file
    if (!inputFile) { // Check if the input file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
    }

    int numAthletes = 0; // Counter to keep track of the number of Athlete objects read from the file

    string line;
    while (getline(inputFile, line)) { // Read Athlete objects from the file until the end of file is reached

        try {
            size_t pos1 = line.find("#"); // Find the position of the first hash symbol
            size_t pos2 = line.find_last_of("#"); // Find the position of the last hash symbol
            size_t pos3 = line.find_last_of('-');
            athletes[numAthletes].name = line.substr(0, pos1); // Extract the name from the line
            athletes[numAthletes].score = line.substr(pos1 + 1, pos2 - pos1 - 1); // Extract the score from the line
            athletes[numAthletes].school = line.substr(pos2 + 1); // Extract the school from the line
            if (athletes[numAthletes].score != "-1")
            {
                athletes[numAthletes].feet = stod(line.substr(pos1 + 1, pos3 - pos1 - 1));
                athletes[numAthletes].inches = stod(line.substr(pos3 + 1, pos2 - pos1 - 1));
            }
            numAthletes++;
            cout << line << endl;
        } 
        catch (exception)
        {
            cout << numAthletes << endl;

        }
    }

    sortAthletes(athletes, numAthletes); // Sort the array of Athletes in ascending order of score using bubble sort
    inputFile.close();
    ofstream outputFile("C:\\track_data\\sorted-athletes.txt"); // Open the output file
    if (!outputFile) { // Check if the output file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
    }

    for (int i = 0; i < numAthletes; i++)
    {
        if (i == numAthletes - 1)
        {
            outputFile << athletes[i].name << "#" << athletes[i].score << "#" << athletes[i].school;
        }
        else
            cout << athletes[i].name << endl;
            outputFile << athletes[i].name << "#" << athletes[i].score << "#" << athletes[i].school << endl;
    }


    // Close the file
    outputFile.close();
}
