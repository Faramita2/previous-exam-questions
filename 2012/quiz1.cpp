#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string   str1, str2;
    ifstream inputFile("string.in");
    ofstream outputFile("string.out");
    getline(inputFile, str1);
    getline(inputFile, str2);

    double a = stod(str1), b = stod(str2);
    double res = a + b;
    outputFile << scientific << setprecision(10) << res;

    return 0;
}