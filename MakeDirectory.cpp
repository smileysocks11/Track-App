#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	// Create a directory on a windows machine
	// with the path c:\track_data\
	
	wstring filePath = L"C:\\track_data"; // create a long string

	LPCWSTR path = filePath.c_str();
	if (CreateDirectory(path, NULL))
	{
		cout << "\nDirectory created: ";
		wcout << filePath << endl;
	}
	else
	{
		cout << "Directory creation failed or directory already exists.\n";
	}
	return 0;
}