#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里设计你的算法 */
const int N = 1005;
int dp[N][N][2];
// 本函数求解答案（损失的最小口感和）
// n：青草棵数
// k：奶牛的初始坐标
// x：描述序列 x（这里需要注意的是，由于 x 的下标从 1 开始，因此 x[0] 的值为 -1，你可以忽略它的值，只需知道我们从下标 1 开始存放有效信息即可），意义同题目描述
// 返回值：损失的最小口感和
int getAnswer(int n, int k, vector<int> x)
{
    /* 请在这里设计你的算法 */
    sort(x.begin(),x.end());
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 1; j++)
            dp[i][i][j] = abs(x[i] - k) * n;

    for (int d = 1; d < n; d++)
        for (int l = 1; l <= n-d; l++)
        {
            int r = l + d;
            dp[l][r][0] = min(dp[l + 1][r][0] + (n - r + l) * abs(x[l] - x[l + 1]), dp[l + 1][r][1] + (n - r + l) * abs(x[l] - x[r]));
            int ll = dp[l][r - 1][0] + (n - r + l) * abs(x[r] - x[l]);
            int lr = dp[l][r - 1][1] + (n - r + l) * abs(x[r] - x[r - 1]);
            dp[l][r][1] = min(ll, lr);
        }

    return min(dp[1][n][0], dp[1][n][1]);
}

// ================= 代码实现结束 =================

int main()
{
    int n, k, tmp;
    vector<int> x;
    scanf("%d%d", &n, &k);
    x.clear();
    x.push_back(-1);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &tmp);
        x.push_back(tmp);
    }
    int ans = getAnswer(n, k, x);
    printf("%d\n", ans);
    return 0;
}

// 我们先从另一个角度看答案，即损失的总口感：从初始状态到奶牛吃掉第 1 棵草之间的时间（我们在下面把它叫做第 1 段时间），所有的 n 棵青草都在流失口感；……；从奶牛吃掉第 i 棵草到它吃掉第 i+1 棵草之间的时间（我们在下面把它叫做第 i+1 段时间），还没有被吃掉的 n-i 棵草都在流失口感；……]

// [于是我们发现，第 i 段时间对答案的贡献，为这段时间的长度与 n-i+1 的乘积。]

// [接着，我们再来关注最优策略。吃完一棵草后（包括初始时），奶牛的最优策略一定是直奔另一棵草。]

// [由于奶牛不会飞，所以奶牛走过的所有路一定是一段连续的区间。]

// [显然地，被奶牛经过过的地方，按最优策略，一定不会留下青草。]

// [所以我们可以**将所有青草的坐标排序**（下面我们都使用排完序后的编号），然后用 dp[l][r][j] 表示吃完 [l,r] 范围内的青草时的最小答案，j 只有 0,1 两种取值，分别表示奶牛吃完最后一棵草停在青草 l 还是 r 上（只有可能是这两种情况，否则与上面的结论矛盾）。]

// [于是我们就可以轻易地设计出状态转移方程：]

// [dp[l][r][0]=min(dp[l+1][r][0]+(n-r+l)*abs(x[l]-x[l+1]),dp[l+1][r][1]+(n-r+l)*abs(x[l]-x[r]))]

// [dp[l][r][1]=min(dp[l][r-1][1]+(n-r+l)*abs(x[r]-x[r-1]),dp[l][r-1][0]+(n-r+l)*abs(x[r]-x[l]))]

// [边界为：dp[i][i][j]=abs(x[i]-k)*n（对于所有1<=i<=n，j=0,1）]

// [友情提示：请注意枚举顺序。]

//  贡献程度是n-(r-l-1)+1

// for (int l = 1; l <= n; l++)
// {
//     for (int r = l; r <= n; r++)
//     {
//         for (int k = 0; k <= 1; k++)
//         {
//             if (l == r)
//                 dp[l][r][k] = abs(x[i] - k) * n;
//         }
//     }
// }

