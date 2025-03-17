#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned int a, b;
    cin >> a >> b;
    while (b > 0) {
        unsigned int tmp = b;
        b                = a % b;
        a                = tmp;
    }

    cout << a << endl;

    return 0;
}