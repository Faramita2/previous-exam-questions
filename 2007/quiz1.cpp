#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(int n)
{
    string str = to_string(n);
    string rts = str;
    reverse(rts.begin(), rts.end());
    return str == rts;
}

int main()
{
    int n;
    cin >> n;
    cout << (isPalindrome(n) ? "Y" : "N") << endl;

    return 0;
}