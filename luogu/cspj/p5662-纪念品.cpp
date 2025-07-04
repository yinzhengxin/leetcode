#include <iostream>
#include <vector>

using namespace std;

/* mostProfileForOneDay 一天的最大盈利
0-1 背包问题：1.物品个数没有限制 2.不要求恰好装满
DP[i,m] = max{DP[i-1, m], dp[i-1, m-x*Vi] + x*Wi} 由于这里的物品个数没有限制，所以有一个参数为x。
上述的维度没有化简的时候，DP数组为2维，函数为3层循环，i = 1~N，m = 1~M，x = 1~M/Vi
上述DP方程可以进行化简成，DP数组为1维，函数为2层循环。
DP[m] = max{dp[m], dp[m-Vi]+Wi} 循环 i = 1~N，m=1~M。这里的M为正循环，对于物品限制为1个的时候，这里M=M~1
*/
int mostProfileForOneDay(int m, int n, vector<int> &v, vector<int> &w)
{
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            if (j >= v[i])
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    // cout << dp[m] << endl;
    return dp[m];
}

int main()
{
    int T, N, M;
    cin >> T >> N >> M;
    int curMoney = M;
    vector<int> v1(N, 0), v2(N, 0), w(N, 0);
    // 1. 读取第1行数据到 v1
    for (int i = 0; i < N; ++i)
    {
        int value;
        cin >> value;
        v1[i] = value;
    }
    // 2. 从第2行 读到 第T行 的计算
    for (int i = 1; i < T; ++i)
    {
        // 2.1 读数据
        for (int j = 0; j < N; ++j)
        {
            int value;
            cin >> value;
            v2[j] = value;
        }
        // 2.2 计算 w
        for (int k = 0; k < N; ++k)
            w[k] = v2[k] - v1[k];
        // 2.3 用v1和w 计算当日最大利润。
        int profile = mostProfileForOneDay(curMoney, N, v1, w);
        curMoney += profile;
        // 2.4 把v2的数据 赋值给 v1
        v1.assign(v2.begin(), v2.end());
    }
    cout << curMoney;
    return 0;
}