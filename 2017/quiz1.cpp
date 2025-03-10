#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string   tmp;
    int      flag = 0;
    ifstream inputFile("input1.txt");
    while (inputFile >> tmp) {
        if (flag) {
            cout << " ";
        }
        flag   = 1;
        tmp[0] = toupper(tmp[0]);
        cout << tmp;
    }
    cout << endl;

    return 0;
}