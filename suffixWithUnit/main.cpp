#include "suffixWithUnit.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    string fileName = "./test/test.txt";
    ifstream myFile(fileName);
    ofstream resultFile("./result/result.txt");
    if(myFile.is_open()) {
        double unit = 0.0; // a variable to retrieve values from myFile
        while(myFile >> unit) {
            resultFile << suffixWithUnit(unit);
            resultFile << endl;
        }
    }
    else return 1;
    myFile.close();
    resultFile.close();
    return 0;
}