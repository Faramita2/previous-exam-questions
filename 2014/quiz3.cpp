#include <iostream>

using namespace std;


bool isParlindrome(string& str) {
    string rts = str;
    reverse(rts.begin(), rts.end());
    return str == rts;
}

string add(string& str) {
    string rts = str;
    reverse(rts.begin(), rts.end());
    char carry = '0';
    string res = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        int tmp = str[i] - '0' + rts[i] - '0' + carry - '0';
        carry = '0' + tmp / 10;
        res.push_back('0' + tmp % 10);
    }
    if (carry == '1') res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    int times = 0;
    string str = to_string(n);
    while (!isParlindrome(str) && ++times < 1000) {
        str = add(str);
    }

    if (times == 1000) {
        cout << "Cannot add to Parlindrome" << endl;
    } else {
        cout << times << endl;
    }

    return 0;
}