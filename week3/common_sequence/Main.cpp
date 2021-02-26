#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */


// 计算最长公共子序列的长度
// n：表示两序列长度
// a：描述序列 a（这里需要注意的是，由于 a 的下标从 1 开始，因此 a[0] 的值为-1，你可以忽略它的值，只需知道我们从下标 1 开始存放有效信息即可） 
// b：描述序列b（同样地，b[0] 的值为 -1）
// 返回值：最长公共子序列的长度
// const int N = 5005;
// int dp[N][N];
// int LCS(int n, vector<int> a, vector<int> b)
// {
//     /* 请在这里设计你的算法 */
//     for (int i = 1; i <= n;i++){
//         for (int j = 1; j <= n;j++){
//             if(a[i]==b[j])
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[n][n];
// }

const int inf = 1e9;

vector<int> pos,f;
int LCS(int n,vector<int> a,vector<int> b)
{
    pos.resize(n + 1);
    f.resize(n + 2, inf);
    for (int i = 1; i <= n;i++)
        pos[b[i]] = i;
    for (int i = 1; i <= n;i++)
        a[i] = pos[a[i]];
    f[0] = 0;
    // for (int i = 1; i <= n;i++)
    //     cout << a[i] << " ";
    // cout << endl;
    for (int i = 1; i <= n; ++i)
        *lower_bound(f.begin(), f.end(), a[i]) = a[i];
    return lower_bound(f.begin(),f.end(),inf)-f.begin()-1;
}
// ================= 代码实现结束 =================

int main() {
    int n, tmp;
    vector<int> a, b;
    scanf("%d", &n);
    a.clear();
    b.clear();
    a.push_back(-1);
    b.push_back(-1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    int ans = LCS(n, a, b);
    printf("%d\n", ans);
    return 0;
}
