#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MAX_TRY 1000

bool isPalindrome(const string &str)
{
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1])
            return false;
    }
    return true;
}

string reverseNum(const string &str)
{
    string newStr = str;
    reverse(newStr.begin(), newStr.end());
    return newStr;
}

string add(const string &str1, const string &str2)
{
    // 123 100
    // 132 001
    // 444 101
    int    maxlen = max(str1.length(), str2.length());
    string res(maxlen, '0');
    int    i = str1.length() - 1, j = str2.length() - 1, k = maxlen - 1;
    int    carry = 0;
    while (i >= 0 & j >= 0) {
        int sum  = (str1[i--] - '0') + (str2[j--] - '0') + carry;
        carry    = sum / 10;
        res[k--] = (sum % 10) + '0';
    }
    if (carry == 1)
        res = "1" + res;
    return res;
}

int main()
{
    string n;
    while (!(cin >> n)) {
        cout << "Input is invalid, try again." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> n;
    }
    int tries = 0;

    while (!isPalindrome(n) && tries < MAX_TRY) {
        tries++;
        n = add(n, reverseNum(n));
        cout << "Tries: " << tries << ", n: " << n << endl;
    }

    cout << (tries == 1000 ? "Cannot add to palindrome." : to_string(tries))
         << endl;

    return 0;
}