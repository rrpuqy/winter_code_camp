#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 给定一个n个点m条边的无向图，第i条边边权为i，求所有需要升级的边
// n：如题意
// m：如题意
// U：大小为m的数组，表示m条边的其中一个端点
// V：大小为m的数组，表示m条边的另一个端点
// 返回值：所有需要升级的边，从小到大排列；第一小问的答案自然即为返回值的size，所以你不必考虑如何返回size
// 升级的道路最短数量为m-1 实际上就是在求最小生成树
// krus算法
int find(vector<int> &a, int i)
{
    int t = i;
    int p = a[t];
    // while (p != 0)
    // {
    //     t = p;
    //     p = a[t];
    // }
    if(p!=0) {
        a[i] = find(a,p);
        return a[i];
    }
    else
        return t;
}
void merge(vector<int> &a, int i, int j)
{
    int p1 = find(a, i);
    int p2 = find(a, j);
    if (p1 != p2)
    {
        a[p2] = p1;
    }
}
vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V) {
    /* 请在这里设计你的算法 */
    vector<int> ans;
    vector<int> uni(n+1,0);
    for(int i=m-1;i>=0;i--){
        int t1 = U[i];
        int t2 = V[i];
        if(find(uni,t1)!=find(uni,t2)){
            merge(uni,t1,t2);
            ans.push_back(i+1);
        }
    }
    // ans.reserve(ans.size());
    reverse(ans.begin(),ans.end());
    return ans;
}

// ================= 代码实现结束 =================

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> U, V;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        U.push_back(u);
        V.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, U, V);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d\n", ans[i]);
    return 0;
}
