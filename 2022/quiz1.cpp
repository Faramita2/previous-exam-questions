#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    cin >> k;

    string s = "";
    while (k > 0) {
        s.push_back((k % 7) + '0');
        k /= 7;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}