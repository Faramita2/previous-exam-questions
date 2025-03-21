#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

void dfs(string& cur, unordered_map<string, vector<string>>& m, bool& isFirst, ofstream& outputFile) {
    if (!isFirst) outputFile << " ";
    isFirst = false;
    outputFile << cur;
    for (auto& task : m[cur]) {
        dfs(task, m, isFirst, outputFile);
    }
}

int main() {
    ifstream inputFile("task.in");
    ofstream outputFile("task.out");
    string tmp;
    unordered_map<string, vector<string>> m;
    map<string, int> indegrees;
    while (getline(inputFile, tmp)) {
        int lPos = tmp.find('(');
        string taskName = tmp.substr(0, lPos);
        if (!indegrees.count(taskName)) indegrees[taskName] = 0;
        int left = lPos + 1;
        int right = tmp.find(',', left);
        vector<string> subTasks;
        while (right != string::npos) {
            string subTask = tmp.substr(left, right - left);
            subTasks.push_back(subTask);
            indegrees[subTask]++;
            left = right + 1;
            right = tmp.find(',', left);
        }

        right = tmp.find(')', left);
        string end = tmp.substr(left, right - left);
        if (end == "NULL") continue;

        subTasks.push_back(tmp.substr(left, right - left));
        m[taskName] = subTasks;
    }

    auto start = *(indegrees.begin());
    cout << start.first << endl;

    string name = start.first;
    bool isFirst = true;
    dfs(name, m, isFirst, outputFile);
    
    return 0;
}