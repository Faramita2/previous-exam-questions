#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("number.in");
    ofstream outputFile("number.out");
    int n;
    inputFile >> n;

    int maxValue = 0, minValue = INT_MAX, value;
    for (int i = 0; i < n; i++) {
        inputFile >> value;
        maxValue = max(value, maxValue);
        minValue = min(value, minValue);
    }

    int a = maxValue, b = minValue, tmp;

    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    outputFile << minValue << " " << maxValue << " " << a;

    return 0;
}