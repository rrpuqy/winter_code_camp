#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
const int inf = -1e10;
// ================= 代码实现开始 =================

// n, m：n 行 m 列
// a：二维数组，行列下标均从 0 开始
// 返回值：价值最大的“折”的价值
int dp[2][N][N];
int col[2][N][N];
int get_answer(int n, int m, int a[N][N])
{
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (cnt <= 0)
                cnt = a[i][j];
            else
                cnt += a[i][j];
            dp[0][i][j] = cnt;
        }
        cnt = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (cnt <= 0)
                cnt = a[i][j];
            else
                cnt += a[i][j];
            dp[1][i][j] = cnt;
        }
    }
    for (int j = 0; j < m; j++)
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt <= 0)
                cnt = a[i][j];
            else
                cnt += a[i][j];
            col[0][i][j] = cnt;
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (cnt <= 0)
                cnt = a[i][j];
            else
                cnt += a[i][j];
            col[1][i][j] = cnt;
        }
    }
    int ret = inf;
    int x,y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int c1 = max(dp[0][i][j], dp[1][i][j]);
            int c2 = max(col[0][i][j], col[1][i][j]);
            int c;
            if (c1 >= 0 && c2 >= 0)
                c = c1 + c2-a[i][j];
            else
                c = max(c1, c2);
            if (c > ret)
            {
                ret = c;
                x = i;
                y = j;
                }
            // ret = max(ret, max(dp[0][i][j], dp[1][i][j]) + max(col[0][i][j], col[1][i][j]));
        }
    // return 0;
    // cout << x << " " << y << endl;
    return ret;
}

// ================= 代码实现结束 =================

int a[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    printf("%d\n", get_answer(n, m, a));
    return 0;
}
