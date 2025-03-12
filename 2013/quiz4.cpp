#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream inputFile("4.in");
    ofstream outputFile("4.out");
    int      n;
    inputFile >> n;
    unordered_set<int> primes;
    for (int i = 2; i < n; i++) {
        if (isPrime(i))
            primes.insert(i);
    }

    for (int i : primes)
        cout << i << " ";
    cout << endl;

    int          res = 0;
    vector<bool> visited(primes.size(), false);
    for (int prime : primes) {
        int remain = n - prime;
        if (primes.find(remain) != primes.end() && !visited[remain]) {
            visited[prime]  = true;
            visited[remain] = true;
            res++;
        }
    }
    cout << "res: " << res << endl;
    outputFile << res;

    return 0;
}