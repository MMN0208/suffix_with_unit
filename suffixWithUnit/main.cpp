#include "suffixWithUnit.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    if(argc < 2) return 1;
    int numberOfTests = stoi(argv[1]);
    for(int i = 0; i < numberOfTests; i++) {
        string fileName = "./test/test" + to_string(i) + ".txt";
        ifstream myFile(fileName);
        double unit = 0.0;
        if(myFile.is_open()) {
            myFile >> unit;
            cout << suffixWithUnit(unit) << endl;
        }
        myFile.close();
    }
    return 0;
}