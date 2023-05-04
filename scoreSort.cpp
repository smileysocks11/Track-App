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

// Uses getNumAthletes
int getNumAthletes();
void output(Athletes [], int, string);
void scoreSort(int);
void populateStructure(Athletes [], int);

// I USE getNumAthlets as numAthletes!!!
// Just a test main to see if it would work
// getNumAthletes must be declared in main.cpp

/*int main() {  TEST MAIN!!! IGNORE THIS!!!
    int numAthletes = getNumAthletes();
    scoreSort(numAthletes);
    return 0;
} */

// Uses numAthlete from getNumAthletes.cpp

/*int getNumAthletes() {   THIS IS JUST A TEST, MY COMPUTER USE THIS, IGNORE THIS!!!
    ifstream inFile("C:\\Users\\Administrator\\Desktop\\Programming\\Programming\\untitled2\\raw-athlete-database.txt");
    if( !inFile)
    {
        cout << "File not found" << endl;
        return 0;
    }
    else
    {
        string line;
        int numAthletes = 0;
        while (getline(inFile, line))
        {
            numAthletes++;
        }
        inFile.close();
        return numAthletes;
    }

} */

void scoreSort(int)
{
    int numAthletes = getNumAthletes();
    Athletes* athleteArr = new Athletes[numAthletes];

    // Populate and output the array of structs
    populateStructure(athleteArr, numAthletes);
    cout << "\nOutputting Athletes in Ascending order...\n\n";
    output(athleteArr, numAthletes, "C:\\Users\\Administrator\\Desktop\\Programming\\Programming\\untitled2\\raw-athlete-database.txt");

    // delete the dynamic array
    delete[] athleteArr;
}

void populateStructure(Athletes athletes[], int numAthletes)
{
    // Declare Variables
    string line, name, school;
    double feet, inches;

    // Open the input file
    ifstream inputFile("C:\\Users\\Administrator\\Desktop\\Programming\\Programming\\untitled2\\raw-athlete-database.txt");
    if (!inputFile) { // Check if the input file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
        return;
    }

    int counter = 0;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        size_t pos1 = line.find("#"); // Find the position of the first hash symbol
        size_t pos2 = line.find_last_of("#"); // Find the position of the last hash symbol
        size_t pos3 = line.find_last_of('-');

        // Check if pos1 and pos3 are not equal to string::npos before extracting the feet and inches values
        if (pos1 == string::npos || pos3 == string::npos) {
            cerr << "Error: Invalid input format in input line " << counter + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }

        // Extract each substring from the input line and assign to the appropriate variable
        name = line.substr(0, pos1);
        school = line.substr(pos2 + 1);

        // Check if the feet and inches substrings can be converted to valid double values
        // using stringstream
        stringstream ss(line.substr(pos1 + 1, pos3 - 1));
        if (!(ss >> feet)) {
            cerr << "Error: Invalid feet value in input line " << counter + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }

        ss = stringstream(line.substr(pos3 + 1, pos2 - 1));
        if (!(ss >> inches)) {
            cerr << "Error: Invalid inches value in input line " << counter + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }


        // Add each to the structure
        athletes[counter].name = name;
        athletes[counter].school = school;
        athletes[counter].feet = feet;
        athletes[counter].inches = inches;
        counter++; // Increment the counter for the number of Athlete objects read

        if (counter >= numAthletes) {
            break; // Stop reading from the input file when the desired number of Athlete objects have been read
        }
    }

    inputFile.close();

    // Sort the athletes array by feet in ascending order using selection sort algorithm
    for (int i = 0; i < counter - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < counter; j++) {
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


void output(Athletes arr[], int size, string outputFileName)
{
    // Remove duplicates by comparing each athlete's name to the names of the other athletes
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].name == arr[j].name) {
                // Remove the duplicate athlete object from the array
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }

    // Sort the athletes array by feet in ascending order using selection sort algorithm
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].feet < arr[minIndex].feet) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Athletes temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Open the output file
    ofstream outputFile(outputFileName);

    // Write the sorted data to the output file
    for (int i = 0; i < size; i++) {
        outputFile << arr[i].name << "#" << arr[i].feet << "-" << arr[i].inches << "#" << arr[i].school << "\n";
    }

    // Close the output file
    outputFile.close();
}
