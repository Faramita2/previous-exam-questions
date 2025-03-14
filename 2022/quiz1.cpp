#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 将10进制正整数转换为7进制的正整数。输入为给定的一个10进制数K(K<1000),计算它的7进制表达形式。如K=15时，输出为21。
int main()
{
    int k;
    cin >> k;

    string s = "";
    while (k > 0) {
        s += to_string(k % 7);
        k /= 7;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}