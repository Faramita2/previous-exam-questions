#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
    }
    
    string s = "";
    while (n > 0) {
        s.push_back((n % 7) + '0');
        n /= 7;
    }
    reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}