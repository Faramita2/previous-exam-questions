#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    ifstream inputFile("expr.in");
    if (!inputFile.is_open()) {
        cerr << "Cannot open expr.in" << endl;
        return 1;
    }
    ofstream outputFile("expr.out");
    if (!outputFile.is_open()) {
        cerr << "Cannot open expr.out" << endl;
        return 1;
    }
    char tmp;
    stack<char> operators;
    string line;
    getline(inputFile, line);
    inputFile.close();
    istringstream iss(line);
    while (iss >> tmp) {
        if (isalpha(tmp)) {
            outputFile << tmp;
        } else if (tmp == '(') {
            operators.push(tmp);
        } else if (isOperator(tmp)) {
            while (!operators.empty() && operators.top() != '(' && getPriority(tmp) <= getPriority(operators.top())) {
                outputFile << operators.top();
                operators.pop();
            } 
            operators.push(tmp);
        } else if (tmp == ')') {
            while (!operators.empty() && operators.top() != '(') {
                outputFile << operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        }
    }

    while (!operators.empty()) {
        if (operators.top() != '(') outputFile << operators.top();
        operators.pop();
    }
    outputFile.close();

    return 0;
}