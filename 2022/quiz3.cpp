#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string word = "";

int maxCharCount(const string &s)
{
    int len      = s.length();
    int maxCount = 0;
    int left     = 0;
    int right    = 0;
    while (left < len && right < len) {
        while (left < len && !isalpha(s[left])) {
            left++;
        }
        right = left;
        while (right < len && s[right] != ' ') {
            right++;
        }

        while (!isalpha(s[right])) {
            right--;
        }
        int curLen = right - left + 1;
        maxCount   = max(curLen, maxCount);
        if (curLen == maxCount)
            word = s.substr(left, curLen);
        left = right + 1;
    }

    return maxCount;
}

// 写代码返回一个英文句子中最长单词的字符个数，
int main()
{
    ifstream inputFile("3.in");
    string   s;
    getline(inputFile, s);

    cout << maxCharCount(s) << endl;
    cout << word << endl;
    return 0;
}