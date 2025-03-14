#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

const static unordered_set<string> keywords = {
    "return",   "if",     "else",   "for",    "while", "switch",  "case",
    "continue", "break",  "static", "struct", "union", "typedef", "sizeof",
    "include",  "define", "const",  "NULL",   "true",  "false",   "int",
    "long",     "float",  "double", "char",   "short", "unsigned"};

bool isValid(string &var)
{

    if (!isalpha(var.front()) && var.front() != '_')
        return false;
    if (keywords.count(var))
        return false;
    for (char c : var) {
        if (!isalpha(c) && !isdigit(c) && c != '_')
            return false;
    }
    return true;
}

int main()
{
    ifstream inputFile("vars.in");
    string   var;
    while (inputFile >> var) {
        cout << "Is " << "\"" << var << "\" a valid C's variable name ? "
             << (isValid(var) ? "Y" : "N") << endl;
    }

    return 0;
}