#include "suffixWithUnit.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    if(argc < 2) return 1;
    int numberOfTests = stoi(argv[1]);
    string fileName = "./test/test.txt";
    ifstream myFile(fileName);
    ofstream resultFile("./result/result.txt");
    double unit = 0.0;
    if(myFile.is_open()) {
        for(int i = 0; i < numberOfTests; i++) {
            myFile >> unit;
            resultFile << suffixWithUnit(unit);
            resultFile << endl;
        }
    }
    else return 1;
    myFile.close();
    resultFile.close();
    return 0;
}