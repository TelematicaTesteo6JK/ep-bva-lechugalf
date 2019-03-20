#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "implementation.h"

using namespace std;

int main() {

    Implementation test;

    ofstream outputFile;
    outputFile.open("results.txt");

    //Equivalence Partitioning
    array<int, 4> testData {-3, 3, 8, 15};
    array<string, 4> expectedResults {"Error", "30", "72", "105"};
    array<string, 4> actualResults;
    array<string, 4> testResults; 

    outputFile << "Equivalence Partitioning\n" << endl;

    for(int i=0; i < testData.size(); i++) {
        try {
            actualResults[i] = to_string(test.calculateAmountToPay(testData[i]));
        } catch(const char* msg){
            actualResults[i] = msg;
        }
        if (actualResults[i] == expectedResults[i]) {
            testResults[i] = "Pass";
        } else {
            testResults[i] = "Fail";
        }

        outputFile << "test data:       " << testData[i] << endl;
        outputFile << "expected result: " << expectedResults[i] << endl;
        outputFile << "actual result:   " << actualResults[i] << endl;
        outputFile << "test result:     " << testResults[i] << endl;
        outputFile << "--------------------------" << endl;
    }
    
    //Boundary Value Analysis
    array<int, 6> testData2 {0, 1, 5, 6, 10, 11};
    array<string, 6> expectedResults2 {"Error", "10", "50", "54", "90", "77"};
    array<string, 6> actualResults2;
    array<string, 6> testResults2;

    outputFile << "\n\nBoundary Value Analysis\n" << endl;

    for(int i=0; i < testData2.size(); i++) {
        try {
            actualResults2[i] = to_string(test.calculateAmountToPay(testData2[i]));
        } catch(const char* msg){
            actualResults2[i] = msg;
        }
        if (actualResults2[i] == expectedResults2[i]) {
            testResults2[i] = "Pass";
        } else {
            testResults2[i] = "Fail";
        }

        outputFile << "test data:       " << testData2[i] << endl;
        outputFile << "expected result: " << expectedResults2[i] << endl;
        outputFile << "actual result:   " << actualResults2[i] << endl;
        outputFile << "test result:     " << testResults2[i] << endl;
        outputFile << "--------------------------" << endl;
    }

    outputFile.close();

    return 0;
}
