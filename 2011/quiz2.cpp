#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int x, y, k;
    cin >> x >> y >> k;
    ofstream outFile("2.out");

    int order = 1;
    for (int r = 0; r <= x; r++) {
        for (int g = 0; g <= y; g++) {
            int b = 8 - r - g;
            outFile << order++ << ". " << r << "红球, " << g << "黄球, " << b
                    << "黑球" << endl;
        }
    }

    return 0;
}