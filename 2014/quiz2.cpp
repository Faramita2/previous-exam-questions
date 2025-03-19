#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    while (n > 0) {
        s.push_back((n % 8 + '0'));
        n /= 8;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}