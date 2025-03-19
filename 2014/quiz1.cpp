#include <iostream>

using namespace std;

int main() {
    string tmp;
    getline(cin, tmp);
    int alpha = 0, number = 0, space = 0, other = 0;
    for (char c : tmp) {
        if (isalpha(c)) alpha++;
        else if(isdigit(c)) number++;
        else if(c == ' ') space++;
        else other++;
    }

    printf("alpha: %d, number: %d, space: %d, other: %d", alpha, number, space, other);
    
    return 0;
}