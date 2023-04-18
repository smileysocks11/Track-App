#include <iostream>

int getFlights();

// test main file
int main() {

    // call getFlights
    int flights = getFlights();

    return 0;
}

int getFlights() {
    /*
     * gets the amount of flights for the meet
     * returns to main
     */
    int flights;

    do {
        std::cout << "How many flights are in the meet?\n>";

        std::cin >> flights;

        if (std::cin.fail()) {
            std::cout << "Your input was not accepted. Please try again.\n\n";
            std::cin.clear();
            std::cin.ignore();
            continue;
        } else {
            break;
        }
    } while (true);

    return flights;
}
