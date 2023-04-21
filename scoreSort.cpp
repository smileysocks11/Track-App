#include <iostream>                                                                         // Cloven Lo
#include <fstream>
#include <string>

using namespace std;

const int MAX_ATHLETES = 100; // Maximum number of athletes that can be read from the input file

struct Athlete {
    string name;
    double score;
    string school;
};

// declares functions
void swapAthletes(Athlete&, Athlete&);
void sortAthletes(Athlete[], int);

// Swaps the values of two Athlete variables
void swapAthletes(Athlete& a, Athlete& b) {
    Athlete temp = a;
    a = b;
    b = temp;
}

// Sorts the array of Athletes in ascending order of score using bubble sort
void sortAthletes(Athlete athletes[], int numAthletes) {
    for (int i = 0; i < numAthletes - 1; i++) {
        for (int j = 0; j < numAthletes - i - 1; j++) {
            if (athletes[j].score > athletes[j + 1].score) {
                swapAthletes(athletes[j], athletes[j + 1]);
            }
        }
    }
}

void scoreSort() {
    ifstream inputFile("C:\\Users\\SSC00042\\Desktop\\raw-athlete-database.txt"); // Open the input file
    if (!inputFile) { // Check if the input file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
    }

    Athlete athletes[MAX_ATHLETES]; // Array to store the Athlete objects read from the file
    int numAthletes = 0; // Counter to keep track of the number of Athlete objects read from the file

    while (inputFile && numAthletes < MAX_ATHLETES) { // Read Athlete objects from the file until the end of file is reached or the maximum number of Athletes is read
        string line;
        getline(inputFile, line); // Read a line from the file
        if (line.empty()) { // Skip empty lines
            continue;
        }
        size_t pos1 = line.find("#"); // Find the position of the first hash symbol
        size_t pos2 = line.find_last_of("#"); // Find the position of the last hash symbol
        athletes[numAthletes].name = line.substr(0, pos1); // Extract the name from the line
        athletes[numAthletes].score = stod(line.substr(pos1 + 1, pos2 - pos1 - 1)); // Extract the score from the line and convert it to a double
        athletes[numAthletes].school = line.substr(pos2 + 1); // Extract the school from the line
        numAthletes++; // Increment the counter for the number of Athlete objects read
    }

    sortAthletes(athletes, numAthletes); // Sort the array of Athletes in ascending order of score using bubble sort
    inputFile.close();
    ofstream outputFile("C:\\Users\\SSC00042\\Desktop\\sorted-athlete-database.txt"); // Open the output file
    if (!outputFile) { // Check if the output file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
    }

    for (int i = 0; i < numAthletes; i++)
    {
        if (i == numAthletes - 1)
            outputFile << athletes[i].name << "#" << athletes[i].score << "#" << athletes[i].school;
        else
            outputFile << athletes[i].name << "#" << athletes[i].score << "#" << athletes[i].school << endl;
    }


    // Close the file
    outputFile.close();
}
