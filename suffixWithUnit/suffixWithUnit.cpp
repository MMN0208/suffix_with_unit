#include "unit.h"
#include "suffixWithUnit.h"
#include <math.h>

std::string suffixWithUnit(double unit) {
    double newUnit = unit;
    int leftOffset = 8; // Number of units before "" in si[]
    int rightOffset = 8; // Number of units after "" in si[]
    int count = 0;
    bool flag = true; // one of the conditions of the for loop
    if(abs(newUnit) >= 1) {
        for(count = 0; count < rightOffset && flag; count++) {
            if(abs(newUnit) < 1000) flag = false;
            else newUnit /= 1000;
        }
        if(!flag) count--; // Because count increases by 1 before the for loop is terminated if flag is false
    }
    else {
        for(count = 0; count > -leftOffset && flag; count--) {
            if(abs(newUnit) >= 1 && abs(newUnit) < 1000) flag = false;
            else newUnit *= 1000;
        }
        if(!flag) count++; // Because count decreases by 1 before the for loop is terminated if flag is false
    }
    return std::to_string(newUnit) + " " + si[count + leftOffset]; // si starts at the smallest unit so by adding the leftOffset to count, we will get the desired unit
}