#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<string>> taskChildrenMap;
unordered_map<int, string>            taskIndexNameMap;
unordered_map<string, int>            taskNameIndexMap;
vector<string>                        scheduleTasks;
int                                   start;

void dfs(int i, vector<int> &visited)
{
    string taskname = taskIndexNameMap[i];
    auto   children = taskChildrenMap[taskname];
    for (auto &child : children) {
        int childIndex = taskNameIndexMap[child];
        if (visited[childIndex])
            continue;
        visited[childIndex] = 1;
        dfs(childIndex, visited);
    }
    scheduleTasks.push_back(taskname);
}

int main()
{
    ifstream inputFile("task.in");
    ofstream outputFile("task.out");
    string   line;
    int      taskCount = 0;
    while (getline(inputFile, line)) {
        vector<string> children;
        int            tmp          = line.find('(');
        string         taskname     = line.substr(0, tmp);
        taskNameIndexMap[taskname]  = taskCount;
        taskIndexNameMap[taskCount] = taskname;
        taskCount++;

        int lPos = tmp + 1;
        int rPos = -1;

        if (line.find("NULL") == -1) {
            while ((rPos = line.find(',', lPos)) != -1) {
                children.push_back(line.substr(lPos, rPos - lPos));
                lPos = rPos + 1;
            };
            if (rPos == -1) {
                rPos = line.find(')', lPos);
                children.push_back(line.substr(lPos, rPos - lPos));
                taskChildrenMap[taskname] = children;
            }
        }
    }

    for (auto &p : taskChildrenMap) {
        cout << p.first << "'s children: ";
        for (auto &s : p.second) {
            cout << s << " ";
        }
        cout << endl;
    }

    vector<int> visited(taskCount, 0);
    for (int i = 0; i < taskCount; i++) {
        if (visited[i])
            continue;
        dfs(i, visited);
    }

    for (int i = taskCount - 1; i >= 0; i--) {
        cout << scheduleTasks[i];
        outputFile << scheduleTasks[i];
        if (i != 0) {
            outputFile << " ";
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}