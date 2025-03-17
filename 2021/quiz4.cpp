#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "";
    while (n > 0) {
        s += to_string(n % 7);
        n /= 7;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}