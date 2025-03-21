#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("2.in");
    ofstream outputFile("2.out");
    
    int tmp;
    int sum = 0;
    while (inputFile >> tmp) {
        sum += tmp;
    }
    
    outputFile << sum;

    return 0;
}