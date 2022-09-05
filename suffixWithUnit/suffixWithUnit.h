#ifndef __SUFFIX_WITH_UNIT__
#define __SUFFIX_WITH_UNIT__

#include <string>
#include <math.h>

std::string si[] = { "Yocto", "Zepto", "Atto", "Femto", "Pico", "Nano", "Micro", "Milli", 
                        "", "Kilo", "Mega", "Giga", "Tera", "Peta", "Exa", "Zetta", "Yotta" };

std::string suffixWithUnit(double unit) {
    double newUnit = unit;
    int count = 0;
    if(abs(newUnit) >= 1) {
        bool flag = true;
        for(count = 0; count < 8 && flag; count++) {
            if(abs(newUnit) < 1000) flag = false;
            else newUnit /= 1000;
        }
        if(!flag) count--; // Because count increases by 1 before the for loop is terminated if flag is false
    }
    else {
        bool flag = true;
        for(count = 0; count > -8 && flag; count--) {
            if(abs(newUnit) >= 1 && abs(newUnit) < 1000) flag = false;
            else newUnit *= 1000;
        }
        if(!flag) count++; // Because count decreases by 1 before the for loop is terminated if flag is false
    }
    return std::to_string(newUnit) + " " + si[count + 8];
}

#endif