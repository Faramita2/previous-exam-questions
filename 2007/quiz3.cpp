#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, dist;
    Edge(int from, int to, int dist): from(from), to(to), dist(dist) {}
};

class UnionSet {
    vector<int> data;
    public:
        UnionSet(int n): data(n) {
            for (int i = 0; i < n; i++) data[i] = i;
        }

        int find(int x) {
            if (data[x] != x) {
                data[x] = find(data[x]);
            }
            return data[x];
        }

        void unite(int a, int b) {
            data[find(a)] = find(b);
        }
};

int main() {
    ifstream inputFile("3.in");
    if (!inputFile.is_open()) {
        cerr << "3.in cannot be opened." << endl;
        return 1;
    }
    int n;
    inputFile >> n;

    int a, b, c;
    vector<Edge> edges;
    while (inputFile >> a >> b >> c) {
        edges.push_back(Edge(a, b, c));
    }
    inputFile.close();

    sort(edges.begin(), edges.end(), [](const auto &l, const auto &r) { return l.dist < r.dist; });

    UnionSet us(n);
    vector<Edge> mst;
    for (auto &e : edges) {
        if (us.find(e.from) != us.find(e.to)) {
            mst.push_back(e);
            us.unite(e.from, e.to);
            if (mst.size() == n - 1) break;
        }
    }

    ofstream outputFile("3.out");
    if (!outputFile.is_open()) {
        cerr << "3.out cannot be opened." << endl;
        return 1;
    }
    // the last line doesn't have \n
    for (int i = 0; i < mst.size(); i++) {
        const auto& e = mst[i];
        outputFile << e.from << " -- " << e.to << " : " << e.dist;
        if (i < mst.size() - 1) outputFile << endl;
    }
    // the last line has \n

    // for (auto& e : mst) {
    //     outputFile << e.from << " -- " << e.to << " : " << e.dist << endl;
    // }
    outputFile.close();

    return 0;
}