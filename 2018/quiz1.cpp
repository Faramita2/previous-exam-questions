#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 2000年1月1日是星期六，现在给你任意一个天数n，
// 代表其距离2000年1月1日有n天，让你求该天是几年几月几日，星期几。
// 比如n = 2，输出“2000 - 1 - 3 Monday”。（记得注意闰年有366天，而且二月有29天）

#define LUNAR_YEAR_DAYS 366
#define NOMAL_YEAR_DAYS 365
class Solution
{
  private:
    bool isLeapYear(int year)
    {
        return ((year % 4 == 0 && year % 100 != 0) ||
                (year % 400 == 0 && year % 3200 != 0) || year % 172800 == 0);
    }

    int calcYear(int year, int &remainDays, bool &isLunar)
    {
        bool flag = isLunar ? remainDays >= LUNAR_YEAR_DAYS
                            : remainDays >= NOMAL_YEAR_DAYS;

        // cout << "Initial year is: " << year << endl;
        // cout << year << " is " << (isLunar ? "lunar" : "normal") << " year."
        //      << endl;

        // could or not do calculation
        while (flag) {
            remainDays -= isLunar ? LUNAR_YEAR_DAYS : NOMAL_YEAR_DAYS;
            year += 1;
            isLunar = isLeapYear(year);

            // cout << "Current year is " << year << endl;
            // cout << year << " is " << (isLunar ? "lunar" : "normal") << "
            // year."
            //      << endl;
            flag = isLunar ? remainDays >= LUNAR_YEAR_DAYS
                           : remainDays >= NOMAL_YEAR_DAYS;
            // cout << "Remain days are " << remainDays << ", it "
            //      << (flag ? "need " : "need not ")
            //      << "to go on year's calculation." << endl;
        }

        return year;
    }

    int calcMonth(int &remainDays, bool isLunar,
                  const vector<int> &normalYearDaysBeforeMonth,
                  const vector<int> &lunarYearDaysBeforeMonth)
    {

        int         month = 0;
        vector<int> daysBeforeMonth =
            isLunar ? lunarYearDaysBeforeMonth : normalYearDaysBeforeMonth;

        for (int i = 1; i < daysBeforeMonth.size(); i++) {
            if (daysBeforeMonth[i - 1] <= remainDays &&
                remainDays < daysBeforeMonth[i]) {
                month = i;
                remainDays -= daysBeforeMonth[i - 1];
                break;
            }
        }

        return month;
    }

  public:
    string solve(int n)
    {
        int    year = 2000, month, day;
        string weekday;

        vector<string> weekdays = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                   "Thursday", "Friday", "Saturday"};

        static const vector<int> normalYearDaysBeforeMonth = {
            0,
            31,
            31 + 28,
            31 + 28 + 31,
            31 + 28 + 31 + 30,
            31 + 28 + 31 + 30 + 31,
            31 + 28 + 31 + 30 + 31 + 30,
            31 + 28 + 31 + 30 + 31 + 30 + 31,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31};

        static const vector<int> lunarYearDaysBeforeMonth = {
            0,
            31,
            31 + 29,
            31 + 29 + 31,
            31 + 29 + 31 + 30,
            31 + 29 + 31 + 30 + 31,
            31 + 29 + 31 + 30 + 31 + 30,
            31 + 29 + 31 + 30 + 31 + 30 + 31,
            31 + 29 + 31 + 30 + 31 + 30 + 31 + 31,
            31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
            31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
            31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
            31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31};

        int  remainDays = n;
        bool isLunar    = isLeapYear(year);

        year    = calcYear(year, remainDays, isLunar);
        month   = calcMonth(remainDays, isLunar, normalYearDaysBeforeMonth,
                            lunarYearDaysBeforeMonth);
        day     = remainDays + 1;
        weekday = weekdays[(n + 5) % 7];

        return to_string(year) + " - " + to_string(month) + " - " +
               to_string(day) + " " + weekday;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    vector<int> testCases;

    ifstream inputFile("input1");
    if (!inputFile.is_open()) {
        cerr << "Error, cannot open \"input1\"" << endl;
    }

    string line;
    while (getline(inputFile, line)) {
        int           n;
        istringstream iss(line);
        iss >> n;
        testCases.push_back(n);
    }

    for (auto n : testCases) {
        cout << "Input: " << n << endl;
        monitor.start();
        auto output = solution.solve(n);
        monitor.stop();
        cout << "Output: " << output << endl;
    }
    cout << endl;

    return 0;
}