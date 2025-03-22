#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int    c = a ^ b;
    string s = "";
    while (c > 0) {
        s += c & 1 ? "1" : "0";
        c >>= 1;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}