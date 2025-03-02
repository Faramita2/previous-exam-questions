#include <iomanip>
#include <iostream>
using namespace std;

// 注意点：
// 1. 阶乘的增长速度和数值溢出问题
// 2. 浮点数精度和舍入误差
// 3. 性能优化（避免重复计算）
// 4. 数学性质的利用（如泰勒展开式的收敛性）
// 5. 输入验证和边界条件处理
// 6. 输出格式的选择
double calculate(int n)
{
    double sum  = 0;
    double term = 1;
    for (int i = 1; i <= n; i++) {
        term /= i;
        sum += term;
        if (term < 1e-16)
            break;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    if (n < 0) {
        cerr << "Error: Input must be a non-negative integer." << endl;
        return 1;
    }
    cout << fixed << setprecision(4) << calculate(n) << endl;
    return 0;
}