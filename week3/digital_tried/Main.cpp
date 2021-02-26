#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 本函数计算答案（最大经过位置数字总和）
// n：描述数字三角形大小，意义同题目描述
// a：描述整个数字三角形，第 i 行的第 j 个数存放在 a[i][j]
// 中（你需要特别注意的是，所有下标均从 1 开始，也就是说下标为 0 的位置将存放无效信息）
// 返回值：最大经过位置数字总和
int dp[1005][1005];
// int dfs(vector<vector<int>> &a, int i, int j, int n)
// {
//    if(dp[i][j])
//        return dp[i][j];
//     if(i==n)
//         return a[i][j];
//     //    dp[i][j] = max(dfs(dp[i + 1][j], i + 1, j, n),);
//     int t1 = a[i][j] + dfs(a, i + 1, j, n);
//     int t2 = a[i][j] + dfs(a, i + 1, j + 1, n);
//     dp[i][j] = max(t1, t2);
//     return dp[i][j];
// }
int dfs(vector<vector<int>> &a, int n)
{
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n;i++){
        for (int j = 1; j <= i;j++){
            j == 1 ? dp[i][j] = dp[i - 1][j] + a[i][j] : dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret = max(ret, dp[n][i]);
    return ret;
}

int getAnswer(int n, vector<vector<int>> a)
{
    /* 请在这里设计你的算法 */
    // return dfs(a, 1, 1, n);
    return dfs(a, n);
}

// ================= 代码实现结束 =================

int main()
{
    int n;
    vector<vector<int>> a;
    scanf("%d", &n);
    a.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        a[i].resize(i + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    int ans = getAnswer(n, a);
    printf("%d\n", ans);
    return 0;
}
