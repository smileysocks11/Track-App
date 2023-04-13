#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ATHLETES = 100; // Maximum number of athletes that can be read from the input file

struct Athlete {
    string name;
    double score;
    string school;
};

// Swaps the values of two Athlete variables
void swapAthletes(Athlete &a, Athlete &b) {
    Athlete temp = a;
    a = b;
    b = temp;
}

// Sorts the array of Athletes in ascending order of score using bubble sort
void sortAthletes(Athlete athletes[], int numAthletes) {
    for (int i = 0; i < numAthletes - 1; i++) {
        for (int j = 0; j < numAthletes - i - 1; j++) {
            if (athletes[j].score > athletes[j+1].score) {
                swapAthletes(athletes[j], athletes[j+1]);
            }
        }
    }
}

int main() {
    ifstream inputFile("athlete-database.txt"); // Open the input file
    if (!inputFile) { // Check if the input file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
        return 1; // Exit the program with a non-zero return value to indicate an error
    }

    Athlete athletes[MAX_ATHLETES]; // Array to store the Athlete objects read from the file
    int numAthletes = 0; // Counter to keep track of the number of Athlete objects read from the file

    while (inputFile && numAthletes < MAX_ATHLETES) { // Read Athlete objects from the file until the end of file is reached or the maximum number of Athletes is read
        string line;
        getline(inputFile, line); // Read a line from the file
        if (line.empty()) { // Skip empty lines
            continue;
        }
        size_t pos1 = line.find(","); // Find the position of the first comma
        size_t pos2 = line.find("#"); // Find the position of the first hash symbol
        size_t pos3 = line.find_last_of("#"); // Find the position of the last hash symbol
        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) { // Check if all three delimiters were found
            athletes[numAthletes].name = line.substr(0, pos1); // Extract the name from the line
            athletes[numAthletes].score = stod(line.substr(pos2 + 1, pos3 - pos2 - 1)); // Extract the score from the line and convert it to a double
            athletes[numAthletes].school = line.substr(pos3 + 1); // Extract the school from the line
            numAthletes++; // Increment the counter for the number of Athlete objects read
        }
    }

    sortAthletes(athletes, numAthletes); // Sort the array of Athletes in ascending order of score using bubble sort

    ofstream outputFile("sorted-athletes.txt"); // Open the output file
    if (!outputFile) { // Check if the output file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
        return 1; // Exit the program with a non-zero return value to indicate an error
    }

    for (int i = 0; i < numAthletes; i++) {
        outputFile << athletes[i].score << ", " << athletes[i].name << ", " << athletes[i].school << endl;
    }

    inputFile.close(); // Close the file
    outputFile.close();

    //cout << "Athletes sorted into sorted-athletes.txt" << endl;

    return 0;
}
