#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    string s = "";
    while (n > 0) {
        int tmp = n % 16;
        s.push_back(tmp > 9 ? 'A' + tmp - 9 : '0' + tmp);
        n /= 16;
    }
    reverse(s.begin(), s.end());
    
    if (isNegative) {
        cout << "-" << s << endl;
    } else {
        cout << s << endl;
    }
    
    return 0;
}