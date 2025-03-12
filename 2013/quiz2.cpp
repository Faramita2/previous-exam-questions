#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("2.in");
    ofstream outputFile("2.out");
    int      n;
    int      sum = 0;
    while (inputFile >> n) {
        sum += n;
    }
    outputFile << sum;

    return 0;
}