#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("1.in");
    ofstream outputFile("1.out");
    if (!inputFile.is_open()) {
        cerr << "Error, i.in cannot be opened." << endl;
        return 1;
    }
    int num;
    int m = 0;
    while (inputFile >> num) {
        m = max(m, num);
    }
    inputFile.close();
    outputFile << m;
    outputFile.close();

    return 0;
}