#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}

int daysInMonth(int year, int month) {
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

int main() {
    int n;
    cin >> n;

    int year = 2000, month = 1, day = 1;
    int days = n;
    while (days > 0) {
        int daysInCurrentMonth = daysInMonth(year, month);
        if (days >= daysInCurrentMonth - day + 1) {
            days -= (daysInCurrentMonth - day + 1);
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        } else {
            day += days ;
            days = 0;
        }
    }

    vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    string weekday = weekdays[(n + 6) % weekdays.size()];

    cout << year << "-" << month << "-" << day << " " << weekday << endl;

    return 0;
}