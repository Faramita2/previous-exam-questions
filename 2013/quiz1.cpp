#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("1.in");
    ofstream outputFile("1.out");
    
    int maxNum = 0;
    int tmp;
    while (inputFile >> tmp) {
        maxNum = max(tmp, maxNum);
    }

    outputFile << maxNum;

    return 0;
}