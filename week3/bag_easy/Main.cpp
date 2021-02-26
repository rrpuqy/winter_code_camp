#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// n：物品个数
// V：背包的体积
// t：长度为n的数组，第i个元素若为0，表示物品i为单个物品；若为1，表示物品i为多个物品。（i下标从0开始，下面同理）
// w：长度为n的数组，第i个元素表示第i个物品的价值
// v：长度为n的数组，第i个元素表示第i个物品的体积
// 返回值：最大价值之和
vector<vector<int>> dp;
int getAnswer(int n, int V, vector<int> t, vector<int> w, vector<int> v)
{
    /* 请在这里设计你的算法 */
    dp.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        dp[i].resize(V + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int v_t = v[i - 1], w_t = w[i - 1], is_mul = t[i - 1];
        for (int j = 1; j <= V; j++)
        {
            // for (int k = 0; k <= V / v[i - 1];k++)
            // {

            // }
            if (!is_mul)
            {
                j >= v_t ? dp[i][j] = max(dp[i - 1][j - v_t] + w_t, dp[i - 1][j]) : dp[i][j] = dp[i - 1][j];
            }
            else
            {
                j >= v_t ? dp[i][j] = max(dp[i][j - v_t] + w_t, dp[i - 1][j]) : dp[i][j] = dp[i - 1][j];
            };
            // if (k*v_t==j){
            //     k++;
            // }
            // else
            //     dp[i][j] =max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][V];
}
int f[5005];

int getAnswer1(int n, int V, vector<int> t, vector<int> w, vector<int> v)
{
    for (int i = 0; i < n; ++i)
        if (t[i] == 0)
            for (int j = V; j >= v[i]; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]); //
        else
            for (int j = v[i]; j <= V; j++)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    //
    return f[V];
}

// ================= 代码实现结束 =================

int main()
{
    int n, V;
    scanf("%d%d", &n, &V);
    vector<int> T, W, _V;
    for (int i = 0; i < n; ++i)
    {
        int t, w, v;
        scanf("%d%d%d", &t, &w, &v);
        T.push_back(t);
        W.push_back(w);
        _V.push_back(v);
    }
    printf("%d\n", getAnswer1(n, V, T, W, _V));
    return 0;
}
