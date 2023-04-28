#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//Cloven Lo

using namespace std;

struct Athletes {
    string name;
    string score;
    string school;
    double feet = 0.0;
    double inches = 0.0;
};

// declares function Prototypes
// Changed to void since arrays are passed to functions by reference
void output(Athletes [], int);
void scoreSort(Athletes [], int&);

void scoreSort(Athletes athletes[], int& numAthletes)
{
    // Declare Variables
    string name, school, score;
    double feet, inches;

    // Open the input file
    ifstream inputFile("C:\\\\track_data\\\\raw-athlete-database.txt");
    if (!inputFile) { // Check if the input file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
        return;
    }

    while (numAthletes < 100 && inputFile) { // Read Athlete objects from the file until the end of file is reached or 100 athletes have been read

        string line;
        getline(inputFile, line);
        if (line.empty()) {
            continue; // Skip empty lines
        }

        size_t pos1 = line.find("#"); // Find the position of the first hash symbol
        size_t pos2 = line.find_last_of("#"); // Find the position of the last hash symbol
        size_t pos3 = line.find_last_of('-');

        // Check if pos1 and pos3 are not equal to string::npos before extracting the feet and inches values #PROBLEM HERE!!!
        if (pos1 == string::npos || pos3 == string::npos) {
            cerr << "Error: Invalid input format in input line " << numAthletes + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }

        // Extract each substring from the input line and assign to the appropriate variable
        name = line.substr(0, pos1);
        score = line.substr(pos1 + 1, pos2 - pos1 - 1);
        school = line.substr(pos2 + 1);

        // Check if the feet and inches substrings can be converted to valid double values
        // using stringstream
        stringstream ss(line.substr(pos1 + 1, pos3 - 1));
        if (!(ss >> feet)) {
            cerr << "" << numAthletes + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }

        ss = stringstream(line.substr(pos3 + 1, pos2 - 1));
        if (!(ss >> inches)) {
            cerr << "Error: Invalid inches value in input line " << numAthletes + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }

        // Add each to the structure
        athletes[numAthletes].name = name;
        athletes[numAthletes].score = score;
        athletes[numAthletes].feet = feet;
        athletes[numAthletes].inches = inches;
        athletes[numAthletes].school = school;
        numAthletes++; // Increment the counter for the number of Athlete objects read
    }
    inputFile.close();
    cout << "\nThere were " << numAthletes << " total lines read from the file.\n";
    cout << "\n------------------------------";

    // Sort the athletes array by feet in ascending order using selection sort algorithm
    for (int i = 0; i < numAthletes - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numAthletes; j++) {
            if (athletes[j].feet < athletes[minIndex].feet) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Athletes temp = athletes[i];
            athletes[i] = athletes[minIndex];
            athletes[minIndex] = temp;
        }
    }
}


void output(Athletes arr[], int size)
{
    // Remove duplicates by comparing each athlete's name to the names of the other athletes
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].name == arr[j].name) {
                // Remove the duplicate athlete object from the array
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; // Decrease the size of the array
                j--; // Decrement j so it continues to check the current position again
            }
        }
    }

    int index = 0;
    for (index = 0; index < size; index++)
    {
        //Output the structure
        cout << "Thrower: " << arr[index].name << endl;
        cout << "School: " << arr[index].school << endl;
        cout << "Distance Thrown: " << arr[index].feet <<
             " feet, " << arr[index].inches << " inches\n";
        cout << endl;
    }
    cout << "There were " << index << " total throwers in the structure.\n";
}
