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
int displayMenu(int choice, bool throw_done)
{
    // menu before throws
    while (choice != 5 && throw_done == 0)
    {

        do // validate the menu choice
        {
            // output the table for the user
            cout << "\nOperation EHS Track"
                << "\n---------------------------"
                << "\n1. Add an athlete"
                << "\n2. Begin throwing"
                << "\n3. View all athletes"
                << "\n4. Adjust the flights"
                << "\n5. Quit"
                << "\n----------------------------"
                << "\nEnter your choice: ";

            // get the choice from the user
            cin >> choice;
            if (cin.fail())
            {
                // tell the user off
                cout << "\nPlease enter reasonable characters.\n";

                // clear the stream
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        } while (choice < 1 || choice > 5);

        // return to get back to the main file
        return choice;

    }

    // menu after throws
    while (choice != 4 && throw_done == 1)
    {

        do // validate the menu choice
        {
            // output the table for the user
            cout << "\nOperation EHS Track"
                << "\n---------------------------"
                << "\n1. View all athletes"
                << "\n2. Check the leaderboard"
                << "\n3. Run finals"
                << "\n4. Quit"
                << "\n----------------------------"
                << "\nEnter your choice: ";

            // get the choice from the user
            cin >> choice;
            if (cin.fail())
            {
                // tell the user off
                cout << "\nPlease enter reasonable characters.\n";

                // clear the stream
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else
                cin.ignore();
        } while (choice < 1 || choice > 4);

        // return to get back to the main file
        return choice;

    }

}