#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream     inputFile("pre.in");
    vector<char> exp;
    char         c;
    while (inputFile >> c) {
        exp.push_back(c);
    }
    stack<double> operands;
    for (int i = exp.size() - 1; i >= 0; i--) {
        c = exp[i];
        if (isdigit(c))
            operands.push(c - '0');
        else {
            double a = operands.top();
            operands.pop();
            double b = operands.top();
            operands.pop();
            if (c == '+')
                operands.push(a + b);
            else if (c == '-')
                operands.push(a - b);
            else if (c == '*')
                operands.push(a * b);
            else
                operands.push(a / b);
        }
    }

    double res = operands.top();
    if (res == (int)res) {
        cout << (int)res << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}