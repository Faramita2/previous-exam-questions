#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    stringstream buffer;
    buffer << inputFile.rdbuf();

    vector<string> lines;
    string currentLine;
    string article = buffer.str();
    for (int i = 0; i < article.length(); i++) {
        char c = article[i];
        if (isalpha(c) || c == ' ') {
            currentLine.push_back(c);
        } else if (c == '!') {
            currentLine.pop_back();
        } else if (c == '*' && !lines.empty()) {
            lines.pop_back();
        } else if (c == '>') {
            int j = i - 1;
            while (j >= 0 && currentLine[j] == ' ') j--;
            while (j >= 0 && currentLine[j] != ' ') j--;
            currentLine[j + 1] = toupper(currentLine[j + 1]);
        } else if (isdigit(c)) continue;
        else if (c == '\n') {
            lines.push_back(currentLine);
            currentLine.clear();
        }
    }
    if (!currentLine.empty()) lines.push_back(currentLine);

    for (auto& line : lines) cout << line << endl;

    return 0;
}