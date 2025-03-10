#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int getGap(int startHour, int startMinute, int endHour, int endMinute)
{
    return startHour * 60 + startMinute - endHour * 60 - endMinute;
}

int main()
{
    unordered_map<string, int> timetrack;
    ifstream                   inputFile("input2.txt");
    int                        n;
    inputFile >> n;

    string id, ans;
    int    startHour, startMinute, endHour, endMinute;
    int    longest = 0;
    // SA0010101 07:22 22:01
    for (int i = 0; i < n; i++) {
        inputFile >> id;
        inputFile >> startHour;
        // skip semicolon
        inputFile.ignore(1);
        inputFile >> startMinute;
        inputFile >> endHour;
        inputFile.ignore(1);
        inputFile >> endMinute;
        int tmp;

        if (endHour <= startHour && endMinute <= startMinute) {
            tmp = 24 * 60 - getGap(endHour, endMinute, startHour, startMinute);
        } else {
            tmp = getGap(startHour, startMinute, endHour, endMinute);
        }
        timetrack[id] += tmp;
    }

    for (auto &p : timetrack) {
        if (p.second > longest) {
            longest = p.second;
            ans     = p.first;
        }
    }
    cout << ans;

    return 0;
}