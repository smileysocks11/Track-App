/*
 * brighton hilyard's file
*/


#include <iostream>

struct athletes {

    std::string name;
    std::string school;
    std::string max;
    std::string throw1, throw2, throw3;
    std::string bestThrow;
    int flightNum;
};

bool athleteChecker(const athletes& athlete);

int main() {
    /*
     * this is a test main function
     * it calls functions and creates test variables
     * inside of the test struct
     */

    athletes athlete;

    // simulating a void throw
    athlete.name = "Jerry";

    athlete.throw1 = "54";
    athlete.throw2 = "";
    athlete.throw3 = "694";

    bool finishedThrowing = athleteChecker(athlete);

    return 0;
}

bool athleteChecker(const athletes& athlete) {
    /*
     * checks if the provided athlete has missed any throws
     * returns a bool finishedThrowing
     * also outputs a statement saying how many throws
     * were missed
     */

    int missedThrows = 0;
    bool finishedThrowing = true;

    if (athlete.throw1.empty()) missedThrows += 1;

    if (athlete.throw2.empty()) missedThrows += 1;

    if (athlete.throw3.empty()) missedThrows += 1;

    if (missedThrows > 0) {
        finishedThrowing = false;

        std::cout << athlete.name << " has missed " << missedThrows << " throw.\n";
    }

    return finishedThrowing;
}
