#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}
// Z: 0 1 2 3 4 5 6 7 8 9 10
// M: 1 0 X 9 8 7 6 5 4 3 2
string checkID(string id)
{
    vector<char> z2m = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    vector<int>  weight = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    int sum = 0;
    for (int i = 0; i < id.length() - 1; i++) {
        sum += (id[i] - '0') * weight[i];
    }

    char checkCode = id.back();
    char code      = z2m[sum % 11];

    return code == checkCode ? "YES" : "NO";
}

int main()
{
    string id1 = "317359198001011725";
    cout << "Is id: " << id1 << " valid ?\n" << checkID(id1) << endl;

    // 错误的case!
    string id2 = "37070419881216001X";
    cout << "Is id: " << id2 << " valid ?\n" << checkID(id2) << endl;

    string id3 = "532719198001012151";
    cout << "Is id: " << id3 << " valid ?\n" << checkID(id3) << endl;

    string id4 = "336228198001014603";
    cout << "Is id: " << id4 << " valid ?\n" << checkID(id4) << endl;

    string id5 = "41472119800101353X";
    cout << "Is id: " << id5 << " valid ?\n" << checkID(id5) << endl;

    return 0;
}