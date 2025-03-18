#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int calculateTime(int startHour, int startMinute, int endHour, int endMinute) {
    int startTime = startHour * 60 + startMinute;
    int endTime = endHour * 60 + endMinute;

    if (endTime < startTime) {
        endTime += 24 * 60;
    }

    return endTime - startTime;
}

int main() {
    ifstream inputFile("input2.txt");
    if (!inputFile.is_open()) {
        cerr << "ERROR" << endl;
        return 1;
    }
    
    int m;
    inputFile >> m;
    string serial;
    char colon;
    int startHour, startMinute, endHour, endMinute;
    unordered_map<string, int> serialTimeMap;

    for (int i = 0; i < m; i++) {
        inputFile >> serial;
        inputFile >> startHour >> colon >> startMinute >> endHour >> colon >> endMinute;
        serialTimeMap[serial] += calculateTime(startHour, startMinute, endHour, endMinute);
    }

    int longest = 0;
    string longestSerial = "";
    for (auto& p : serialTimeMap) {
        if (p.second > longest) {
            longest = p.second;
            longestSerial = p.first;
        }
    }

    cout << longestSerial << endl;

    return 0;
}