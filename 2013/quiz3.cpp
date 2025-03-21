#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("3.in");
    ofstream outputFile("3.out");
    int n;
    inputFile >> n;
    string s = "";
    while (n > 0) {
        s.push_back('0' + n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    outputFile << s;

    return 0;
}