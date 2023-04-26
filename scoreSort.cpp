#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

const int MAX_ATHLETES = 100; // Maximum number of athletes that can be read from the input file

struct Athlete {
    string name;
    string score;
    string school;
    double feet;
    double inches;
};

// declares functions
void swapAthletes(Athlete&, Athlete&);
void sortAthletes(Athlete[], int);
bool deleteDuplicates(Athlete[], int&);
void writeAthletes(Athlete[], int);

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
            if (athletes[j].score > athletes[j + 1].score && athletes[j].score != "-1") {
                swapAthletes(athletes[j], athletes[j + 1]);
            }
        }
    }
}

// Deletes athletes with duplicate names from the array and returns true if any duplicates were found
bool deleteDuplicates(Athlete athletes[], int& numAthletes) {
    bool deleted = false;
    for (int i = 0; i < numAthletes; i++) {
        if ((i > 0 && athletes[i].name == athletes[i - 1].name) ||
            (i < numAthletes - 1 && athletes[i].name == athletes[i + 1].name)) {
            athletes[i].score = "-1";
            deleted = true;
        }
    }
    return deleted;
}

// Writes the sorted array of Athletes to an output file, deleting duplicates
void writeAthletes(Athletes* athletes, int numAthletes) {

    // Open the input file
    ifstream inputFile("C:\\track_data\\raw-athletes.txt");
    if (!inputFile) {
        cerr << "Error opening file" << endl;
        return;
    }

    // Open the output file
    ofstream outputFile("C:\\track_data\\sorted-athletes.txt");
    if (!outputFile) {
        cerr << "Error opening file" << endl;
        inputFile.close();
        return;
    }

    // Declare an array to keep track of which Athletes to delete
    bool deleteAthlete[MAX_ATHLETES] = { false };

    // Read the input file line by line and mark duplicates for deletion
    string line;
    while (getline(inputFile, line)) {
        try {
            size_t pos1 = line.find("#");
            string name = line.substr(0, pos1);

            // Check if the name is a duplicate
            bool duplicateFound = false;
            for (int i = 0; i < numAthletes; i++) {
                if (athletes[i].name == name) {
                    if (!duplicateFound) {
                        // This is the first occurrence of a duplicate name, don't delete it
                        duplicateFound = true;
                    }
                    else {
                        // This is the second occurrence of a duplicate name, mark it for deletion
                        deleteAthlete[i] = true;
                    }
                }
            }
        }
        catch (exception) {
            // Handle any exceptions that may occur while processing the file
            cerr << "Error processing line: " << line << endl;
        }
    }

    // Write the sorted and de-duplicated Athletes to the output file
    for (int i = 0; i < numAthletes; i++) {
        if (!deleteAthlete[i]) {
            outputFile << athletes[i].name << "#" << athletes[i].score << "#" << athletes[i].school << endl;
        }
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();
}

void scoreSort(Athletes* athletes) {

    ifstream inputFile("C:\\track_data\\raw-athlete-database.txt"); // Open the input file
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
                athletes[numAthletes].inches = stod(line.substr(pos3 + 1, pos2 - pos3 - 1));
            }
            numAthletes++;
        }
        catch (exception e) // Catch the exception thrown by stod() function
        {
            cerr << "Error converting score for athlete " << numAthletes + 1 << endl;
            cerr << e.what() << endl;
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
        else {
            cout << athletes[i].name << endl;
            outputFile << athletes[i].name << "#" << athletes[i].score << "#" << athletes[i].school << endl;
        }
    }


    // Close the file
    outputFile.close();
}
