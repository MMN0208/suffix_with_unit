#include "unit.h"
#include "suffixWithUnit.h"
#include <math.h>

#define NUM_OF_LEFT_UNITS      8  // Number of units before "" in si[]
#define NUM_OF_RIGHT_UNITS     8  // Number of units after "" in si[]
#define START_INDEX            8  // Starts at "" prefix

std::string suffixWithUnit(double unit) {
    double newUnit = unit;
    int siIndex = START_INDEX;
    if(abs(newUnit) >= 1) {
        while(abs(newUnit) >= 1000 && siIndex < START_INDEX + NUM_OF_RIGHT_UNITS) {
            newUnit /= 1000;
            siIndex++; // move to the next positive power prefix
        }
    }
    else {
        while(abs(newUnit) < 1 && siIndex > START_INDEX - NUM_OF_LEFT_UNITS) { 
            newUnit *= 1000;
            siIndex--; // move to the next negative power prefix
        }
    }
    return std::to_string(newUnit) + " " + si[siIndex];
}