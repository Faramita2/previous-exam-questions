#include <iostream>

using namespace std;

bool isMatched(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) sum += i;
    }
    return sum >= num;
}

int main() {
    bool isFirst = true;
    for (int i = 3; i <= 1000; i++) {
        if (isMatched(i)) {
            if (!isFirst) cout << " ";
            cout << i;
            isFirst = false;
        }
    }

    return 0;
}