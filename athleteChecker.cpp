/*
 * brighton hilyard's file
*/

#include <iostream>
#include "Athletes.h"

/*
 * uses the athletes array
 * and calls athleteChecker to check each athlete's struct
*/
int main() {
    
    int athlete_num = 0;
    int num_athletes = 36;
    while (num_athletes != athlete_num) {
        
        Athletes athlete = athletes[athlete_num];
        
        isFinished = athleteChecker(athlete);
        
        std::cout << isFinished;
        
        athlete_num += 1;
    }
    
}

bool athleteChecker(const Athletes& athlete) {
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
