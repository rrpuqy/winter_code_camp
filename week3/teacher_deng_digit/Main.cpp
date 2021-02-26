#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 计算答案的函数
// n, m, t, d：意义均与题目描述一致
// 返回值：即为答案
const int N = 2005;
// const int T = 205;
// const int inf = 1e9;
// int f[N][N][T];
// int n, m,d;

// int dfs(int v1,int v2,int t){
//     if(t==0)
//         return abs(v1 + v2 - d);
//     if(v1==0 && v2==0){
//         int t1 = f[n][0][t - 1] =  (dfs(n,0 ,t - 1));
//         int t2 = f[0][m][t - 1] = dfs(0, m, t - 1);
//         int t3 = f[0][0][t - 1] = dfs(0, 0, t - 1);
//         return f[v1][v2][t] = min(min(t1, t2),t3);
//     }
//     else if(v1==n && v2==m){
//         int t1 = f[n][0][t - 1] = (dfs(n, 0, t - 1));
//         int t2 = f[0][m][t - 1] = dfs(0, m, t - 1);
//         int t3 = f[n][m][t - 1] = dfs(n, m, t - 1);
//         return f[v1][v2][t] = min(min(t1, t2), t3);
//     }
//     else if(v1==n && v2+n<=m){
//         int t1 = f[0][v2 + n][t - 1] = dfs(0, v2 + n, t - 1);
//         int t2 = f[v1][v2][t - 1] = dfs()
//     }
    
// }

typedef pair<int, int> pil;
#define fi first
#define se second

int mind[N][N];
pil q[N * N];
int qh, qt;

pil to(pil p,int k,int n,int m)
{
    if(k==0) return pil(0,p.se);
    else if( k==1 )
        return pil(p.fi, 0);
    else if (k==2)
        return pil(n, p.se);
    else if(k==3)
        return pil(p.fi, m);
    else if(k==4)
        return pil(p.fi + p.se >= n ? n : p.first + p.second, p.first + p.second <= n ? 0 : p.first + p.second - n);
    else if(k==5)
        return pil(p.fi + p.se <= m ? 0 : p.first + p.second - m, p.first + p.second >= m ? m : p.first + p.second);
    else 
        return p;
}

int getAnswer(int n, int m, int t, int d) {
    /* 请在这里设计你的算法 */
    // if(n>m)
    //     swap(n, m);
    // memset(f, -1, sizeof f);
    // ::n = n;
    // ::m = m;
    // ::d = d;
    memset(mind, -1, sizeof(mind));
    qh = qt = 0;
    q[++qt] = pil(0, 0);
    mind[0][0] = 0;
    while(qh < qt){
        pil u = q[++qh];
        if(mind[u.first][u.second] ==t)
            break;
        for (int k = 0; k < 6;++k){
            pil v = to(u, k, n, m);
            if(mind[v.first][v.second]!=-1)
                continue;
            q[++qt] = v;
            mind[v.fi][v.se] = mind[u.fi][u.se] + 1;
        }
    }

    int ans = d;
    for (int i = 0; i <= n;++i)
        for (int j = 0; j <= m;++j)
            if(mind[i][j]!=-1)
                ans = min(ans,abs(i+j-d));
    return ans;
}


// ================= 代码实现结束 =================

int main() {
    int n, m, t, d;
    scanf("%d%d%d%d", &n, &m, &t, &d);
    int ans = getAnswer(n, m, t, d);
    printf("%d\n", ans);
    return 0;
}
