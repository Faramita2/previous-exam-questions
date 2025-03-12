#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("number.in");
    int      n;
    inputFile >> n;
    inputFile.ignore();
    int num;
    int minNum = INT_MAX, maxNum = INT_MIN;
    for (int i = 0; i < n; i++) {
        inputFile >> num;
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }
    ofstream outputFile("number.out");
    cout << minNum << " " << maxNum << " ";
    outputFile << minNum << " " << maxNum << " ";

    while (minNum != 0) {
        int remain = maxNum % minNum;
        maxNum     = minNum;
        minNum     = remain;
    }
    cout << maxNum;
    outputFile << maxNum;

    return 0;
}