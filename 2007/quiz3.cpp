#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Edge
{
    int from, to, dist;
    Edge(int from, int to, int dist) : from(from), to(to), dist(dist)
    {
    }
};

struct Cmp
{
    bool operator()(const Edge &lE, const Edge &rE)
    {
        return lE.dist > rE.dist;
    }
};

ifstream inputFile("3.in");
ofstream outputFile("3.out");

int                                     n;
vector<Edge>                            mst;
priority_queue<Edge, vector<Edge>, Cmp> edges;
vector<int>                             unionSet;
int                                     setIdx = 1;

void kruskal()
{
    while (!edges.empty()) {
        auto e = edges.top();
        edges.pop();
        int from = e.from, to = e.to;
        int set1 = unionSet[from], set2 = unionSet[to];
        if (!set1 && !set2) {
            unionSet[from] = unionSet[to] = setIdx++;
        } else if (set1 && set2) {
            if (set1 == set2)
                continue;
            for (auto &s : unionSet) {
                if (s == set2)
                    s = set1;
            }
        } else {
            if (!set1)
                unionSet[from] = set2;
            if (!set2)
                unionSet[to] = set1;
        }
        mst.push_back(e);
    }
}

int main()
{
    inputFile >> n;
    unionSet = vector<int>(n + 1, 0);

    int from, to, dist;

    while (inputFile >> from >> to >> dist) {
        edges.push(Edge(from, to, dist));
    };

    kruskal();

    for (auto &e : mst) {
        outputFile << e.from << " -- " << e.to << " : " << e.dist << endl;
    }

    return 0;
}