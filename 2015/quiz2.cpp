#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 设计一个模拟测试系统。
// 输出 0-50 以内 2 个随机数的加或减。
// 从键盘输入答案，每题有2次机会，第一次答对得10分，第二次答对得5分，总共10题，最终输出总得分。
vector<pair<string, string>> solve()
{
    vector<pair<string, string>>  questions;
    random_device                 rd;
    mt19937                       gen(rd());
    uniform_real_distribution<>   opR(0, 1);
    uniform_int_distribution<int> numR(0, 50);
    for (int i = 0; i < 10; i++) {
        string question, answer;
        int    num1 = numR(gen);
        int    num2 = numR(gen);
        if (opR(gen) > 0.5) {
            questions.push_back(
                {to_string(num1) + " + " + to_string(num2) + " = ?",
                 to_string(num1 + num2)});
        } else {
            questions.push_back(
                {to_string(num1) + " - " + to_string(num2) + " = ?",
                 to_string(num1 - num2)});
        }
    }

    return questions;
}

int main()
{
    auto questions = solve();
    int  total     = 0;
    for (auto &question : questions) {
        cout << question.first << " " << question.second << endl;
    }

    for (auto &question : questions) {
        int ans;
        int tries = 2;

        cout << question.first << endl;
        while (true) {
            cin >> ans;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input invalid, input an integer again." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        while (to_string(ans) != question.second && --tries > 0) {
            cout << question.first << endl;
            cin >> ans;
        }

        total += tries * 5;
    }
    cout << "total: " << total << endl;

    return 0;
}