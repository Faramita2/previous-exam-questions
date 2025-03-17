#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isValidWordElement(const string &s, int i)
{
    // 当前字符是连字符，且前后均为字母，则认为是有效连字符
    return s[i] == '-' && i > 0 && isalpha(s[i - 1]) && i + 1 < s.length() &&
           isalpha(s[i + 1]);
}

pair<int, string> findLongestWord(const string &s)
{
    int    maxCount    = 0;  // 最长单词的长度
    string longestWord = ""; // 最长单词
    string currentWord = ""; // 当前正在累积的单词

    for (size_t i = 0; i < s.length(); ++i) {
        if (isalpha(s[i]) || isValidWordElement(s, i)) {
            // 如果当前字符是字母或有效连字符，加入到当前单词中
            currentWord += s[i];
        } else {
            // 遇到非单词字符时，检查当前单词是否为最长单词
            if (!currentWord.empty()) {
                if (currentWord.length() > maxCount) {
                    maxCount    = currentWord.length();
                    longestWord = currentWord;
                }
                currentWord.clear(); // 清空当前单词
            }
        }
    }

    // 处理最后一个单词（如果字符串以字母或有效连字符结尾）
    if (!currentWord.empty()) {
        if (currentWord.length() > maxCount) {
            maxCount    = currentWord.length();
            longestWord = currentWord;
        }
    }

    return {maxCount, longestWord};
}

// 写代码返回一个英文句子中最长单词的字符个数，
int main()
{
    ifstream inputFile("3.in");
    if (!inputFile.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }
    string s;
    getline(inputFile, s);

    auto result = findLongestWord(s);
    cout << result.first << endl;
    cout << result.second << endl;
    return 0;
}