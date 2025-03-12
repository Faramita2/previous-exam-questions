#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("3.in");
    ofstream outputFile("3.out");
    int      n;
    inputFile >> n;
    string res = "";
    while (n > 0) {
        res += to_string(n % 2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    outputFile << res;

    return 0;
}