#include <iostream> // BY NOAH JACKSON
using namespace std;

/*#######################
displayMenu accepts an integer
it's going to display a menu
for the user and prompt them
for an option. It will loop
until the user chooses
a valid option.
it will return the user's
choice
#########################*/
int displayMenu(int choice)
{

    while (choice != 6)
    {

        do // validate the menu choice
        {
            // output the table for the user
            cout << "\nOperation EHS Track"
                << "\n---------------------------"
                << "\n1. Add an athlete"
                << "\n2. Make a throw"
                << "\n3. View all athletes"
                << "\n4. Check the leaderboard"
                << "\n5. Adjust the flights"
                << "\n6. Quit"
                << "\n----------------------------"
                << "\nEnter your choice: ";

            // get the choice from the user
            cin >> choice;
        } while (choice < 1 || choice > 6);

        // return to get back to the main file
        return choice;

    }

}