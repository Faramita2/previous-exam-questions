#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const vector<int>    mcnt  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const vector<int>    ycnt  = {366, 365, 365, 365};
const vector<string> dname = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                              "Wednesday", "Thursday", "Friday"};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int skipPeriod(int &remainingDays, const vector<int> &periods)
{
    int index = 0;
    while (remainingDays >= periods[index % periods.size()]) {
        remainingDays -= periods[index % periods.size()];
        index++;
    }
    return index;
}

string solve(int n)
{
    int    year = 2000, month = 1, date = 1;
    string weekday = dname[n % 7];

    // 跳过年份
    int yearIndex = skipPeriod(n, ycnt);
    year += yearIndex;

    // 判断闰年
    if (isLeapYear(year)) {
        const_cast<int &>(mcnt[1]) = 29; // 修改二月天数
    }

    // 跳过月份
    int monthIndex = skipPeriod(n, mcnt);
    month += monthIndex;

    // 剩余天数即为日期
    date += n;

    // 格式化输出
    ostringstream oss;
    oss << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2)
        << setfill('0') << date << " " << weekday;
    return oss.str();
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}