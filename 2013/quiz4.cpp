#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ifstream inputFile("4.in");
    ofstream outputFile("4.out");
    int n;
    inputFile >> n;
    vector<int> primes;
    int count = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) count++;
    }

   cout << count;

    return 0;
}