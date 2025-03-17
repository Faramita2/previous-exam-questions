#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 给定两个字符用str1和str2，请输出将str1转为str2的最少操作数，要求时间复杂度为O(log(MN))，其中M、N分别是两个字符串的长度。
// 可以对字符围进行3种操作:插入一个字符、删除一个字符、改一个字符。
// 字符串长度满足1<=n<=1000，字符串中只出现小写英文字母。

// 示例输入: nowcoder, new

// 示例输出: 6

// 示例说明:
// "nowcoder"=>"newcoder"(将'o'替换为'e')，修改操作1次
// "nowcoder"=>"new"(删除"coder”)，删除操作5次

int minDistance(string &str1, string &str2)
{
    int m = str1.length();
    int n = str2.length();

    if (m == 0)
        return n;
    if (n == 0)
        return m;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] =
                    min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

int minDistance_optimized(string &str1, string &str2)
{
    int m = str1.length();
    int n = str2.length();

    // 如果其中一个字符串为空，直接返回另一个字符串的长度
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    // 上一行的状态
    vector<int> prev(n + 1, 0);
    // 当前行的状态
    vector<int> curr(n + 1, 0);

    // 初始化第一行
    for (int j = 0; j <= n; j++)
        prev[j] = j;

    for (int i = 1; i <= m; i++) {
        // 初始化当前行的第一个元素
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                int insertCost  = curr[j - 1] + 1;
                int deleteCost  = prev[j] + 1;
                int replaceCost = prev[j - 1] + 1;
                curr[j]         = min({insertCost, deleteCost, replaceCost});
            }
        }
        // 当前行转变为下一轮的上一行
        prev.swap(curr);
    }
    // 最终结果存储在prev[n]中
    return prev[n];
}

int main()
{
    string str1 = "nowcoder";
    string str2 = "new";
    cout << minDistance(str1, str2) << endl;

    return 0;
}