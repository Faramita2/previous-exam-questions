#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func(double x) {
    return 2 * pow(x, 11) - 3 * pow(x, 8) - 5 * pow(x, 3) - 1;
}

int main() {
    double low = 1, high = 2;
    while (high - low > 0.00000001) {
        double mid = low + (high - low) / 2;
        double mval = func(mid);
        if (mval > 0) high = mid;
        else if (mval < 0) low = mid;
        else {
            cout << fixed << setprecision(8) << mval << endl;
            return 0;
        }
    }
    cout << fixed << setprecision(8) << low << endl;

    return 0;
}