#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <numeric>

using namespace std;

string trimTrailingZeros(string& str) {
    size_t ePos = str.find('e');
    if (ePos == string::npos) {
        return str;
    }

    string mantissa = str.substr(0, ePos);
    string exponent = str.substr(ePos + 1);

    size_t lastNonZero = mantissa.find_last_not_of('0');
    if (lastNonZero != string::npos && mantissa[lastNonZero] == '.') {
        mantissa = mantissa.substr(0, lastNonZero + 2);
    } else {
        mantissa = mantissa.substr(0, lastNonZero + 1);
    }

    int expValue = stoi(exponent);
    ostringstream oss;
    oss << "e" << expValue;

    return mantissa + oss.str();
}

int main() {
    string a, b;
    ifstream inputFile("string.in");
    ofstream outputFile("string.out");
    getline(inputFile, a);
    getline(inputFile, b);

    try {
        double result = stod(a) + stod(b);

        double intPart, fracPart;
        fracPart = modf(result, &intPart);

        if (fracPart == 0) {
            cout << static_cast<long long>(result);
        } else {
            ostringstream oss;
            oss << scientific << setprecision(10) << stod(a) + stod(b);
            string resultStr = oss.str();
            string trimmedResult = trimTrailingZeros(resultStr);

            cout << trimmedResult;
        }
    } catch (...) {
        cerr << "Error" << endl;
        return 1;
    }

    return 0;
}
