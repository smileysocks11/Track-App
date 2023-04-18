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
    std::cout << "How many flights are in the meet?\n>";
    std::cin >> flights;

    return flights;
}