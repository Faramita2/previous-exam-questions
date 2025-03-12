#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("ticket.in");
    ofstream outputFile("ticket.out");
    int      n, m;
    inputFile >> n >> m;

    vector<int> delta(100001, 0);
    vector<int> currentPassengers(100001, 0);
    for (int i = 0; i < n; ++i) {
        int a, b, k;
        inputFile >> a >> b >> k;

        bool canSatisfy = true;
        for (int j = a; j < b; ++j) {
            if (currentPassengers[j] + k > m) {
                canSatisfy = false;
                break;
            }
        }
        outputFile << (canSatisfy ? "1" : "0") << "\n";

        if (canSatisfy) {
            for (int j = a; j < b; ++j) {
                currentPassengers[j] += k;
            }
        }
    }

    return 0;
}