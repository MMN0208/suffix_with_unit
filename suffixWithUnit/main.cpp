#include "suffixWithUnit.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    int sel;
    do {
        cout << "Input the way you want to run the test:\n0: console input\n1: ./test/test.txt\nYour input: ";
        cin >> sel;
    } while(sel < 0 || sel > 1);
    string fileName = "./test/test.txt";
    ifstream myFile(fileName);
    ofstream resultFile("./result/result.txt");
    switch(sel) {
        case 0:
            int n;
            do {
                cout << "Input the number of tests you want to run: ";
                cin >> n;
            } while(n < 1);
            cout << "Input your test(s) here:\n";
            double test;
            for(int i = 0; i < n; i++) {
                cin >> test;
                resultFile << test << " = " << suffixWithUnit(test) << endl;
                cout << test << " = " << suffixWithUnit(test) << endl;
            }
            break;
        case 1:
            if(myFile.is_open()) {
                double unit = 0.0; // a variable to retrieve values from myFile
                while(myFile >> unit) {
                    resultFile << unit << " = " << suffixWithUnit(unit) << endl;
                    cout << unit << " = " << suffixWithUnit(unit) << endl;
                }
            }
            else return 1;
            myFile.close();
            resultFile.close();
            break;
    }
    return 0;
}