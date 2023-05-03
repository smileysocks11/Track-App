#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Noah McGinley

// Prototype Functions
void scoreSort();
int getnumAthletes(ifstream&);
int getTotalQtrInches(string);


// Declares structure
struct Athletes
{
    string name;
    string school;
    string max;
    int totalQtrInches;

};


int main()
{
 
    scoreSort();
}


/*-------------------------------------
# scoreSort() accepts no arguments
# It reads the athletes file and appends
# the information into the Athletes structure.
# It sorts the structure by comparing the
# max of the athletes converted into quarter inches
---------------------------------------*/
void scoreSort()
{
    // Variables
    int numAthletes;
    int countableMax = 0; // Used to sort the max by quarter inches
    string line;
    string name;
    string school;
    string max;
    ifstream inFile("C:\\track_data\\raw-athletes.txt");
    numAthletes = getnumAthletes(inFile);
    cout << numAthletes;

    struct Athletes athletes[42];

    inFile.clear();
    inFile.seekg(0);

    for (int i = 0; i < numAthletes; i++)
    {
        // Reads file
        getline(inFile, name, '#');
        athletes[i].name = name;
        getline(inFile, max, '#');
        int countableMax = getTotalQtrInches(max);

        // Populates structure
        athletes[i].max = max;
        athletes[i].totalQtrInches = countableMax;

        getline(inFile, school);
        athletes[i].school = school;
    }


    inFile.close();

    // Outputs structure
    for (int i = 0; i < numAthletes; i++)
    {
        cout << athletes[i].name << "\t\t\t\t";
        cout << athletes[i].school << "\t\t\t\t";
        cout << athletes[i].max << "\t\t\t\t" << endl;
       // cout << athletes[i].totalQtrInches << endl;
    }


    // To write back to file
    /*
    ofstream outFile(R"(C:\Users\SNM00013\Desktop\CPP-2022\files\data_files\athletesFile.txt)");

    // Writes sorted data back to file
    for (int i = 0; i < numAthletes; i++)
    {
        outFile << athletes[i].name << "#";
        outFile << athletes[i].max << "#";
        outFile << athletes[i].school << endl;
    }

    outFile.close();
    */
}


// Gets the number of athletes
int getnumAthletes(ifstream& inFile)
{
    string line;
    int numAthletes = 0;
    while (getline(inFile, line))
    {
        numAthletes++;
    }
    return numAthletes;
}


// Converts max all into quarter inches
int getTotalQtrInches(string max)
{

    if (max == "-1")
    {
        return 0;
    }

    int countableMax;
    string delimiter = "-";

    size_t pos = 0;
    string spot;
    while ((pos = max.find(delimiter)) != string::npos) {
        spot = max.substr(0, pos);
        max.erase(0, pos + delimiter.length());
    }
    int feet = stoi(spot);
    int inches = stoi(max);

    delimiter = ".";

    while ((pos = max.find(delimiter)) != string::npos) {
        spot = max.substr(0, pos);
        max.erase(0, pos + delimiter.length());
    }
    int qtrInches = stoi(max);

    countableMax = (feet * 48) + (inches * 4) + (qtrInches);
    
    return countableMax;
}

bool compare(Athletes a, Athletes b)
{
    if (a.totalQtrInches < b.totalQtrInches)
        return 1;
    else
        return 0;
}
