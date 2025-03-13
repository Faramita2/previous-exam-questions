#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ifstream inputFile("input.txt");

char toggleCase(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}

int main()
{
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string str = buffer.str();

    string         res;
    vector<string> lines;
    string         currentLine;

    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];

        if (isalpha(c) || c == ' ') {
            currentLine += c;
        } else if (c == '!') {
            if (!currentLine.empty()) {
                currentLine.pop_back();
            }
        } else if (c == '*') {
            if (!lines.empty()) {
                lines.pop_back();
            }
        } else if (c == '>') {
            if (!currentLine.empty()) {
                int j = currentLine.size() - 1;
                while (j >= 0 && currentLine[j] == ' ')
                    --j;
                while (j >= 0 && isalpha(currentLine[j]))
                    --j;
                if (j + 1 < currentLine.size()) {
                    currentLine[j + 1] = toggleCase(currentLine[j + 1]);
                }
            }
        } else if (isdigit(c)) {
            continue;
        } else if (c == '\n') {
            lines.push_back(currentLine);
            currentLine.clear();
        }
    }

    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    for (const auto &line : lines) {
        cout << line << endl;
    }

    return 0;
}