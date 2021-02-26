#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 求解棋盘上最多能放多少个“车”
// n：棋盘的大小为n×n的
// board：所给棋盘，对于某个位置上的数：若值为1表示可以放“车”；若值为0表示不能放“车”
// 返回值：能放“车”的最大个数

// 对放车的位置进行尝试
struct node
{
    int x, y;
    node(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};
vector<node> car;
int check_x[505];
int check_y[505];
vector<int> ans;
int dfs1(int i, int n)
{
    if (i == n)
    {
        // for(int &i:ans)
        //     cout << i << " ";
        // cout << endl;
        return 0;
    }
       
    int x = car[i].x;
    int y = car[i].y;
    int t2 = 0;
    if (check_x[x] == 0 && check_y[y] == 0)
    {
        check_x[x] = 1;
        check_y[y] = 1;
        // cout << x << y << endl;
        ans.push_back(i);
        t2 = 1 + dfs1(i + 1, n);
        ans.pop_back();
        check_x[x] = 0;
        check_y[y] = 0;
    }
    int t1 = dfs1(i + 1, n);
    return max(t1, t2);
    // if (check[x] && check[y])
    // {
    //     check[x] = 0;3
    //     check[y] = 0;
    //     cnt--;
    // }
}
const int N = 505 * 2, M = N * N;
struct E{
    int next, to;
}e[M];

int cnt, ihead[N], mc[N];
bool vis[N];
// cnt 边的序号 
//ihead 邻接表的头 
//mc 表示每个点匹配到的另一个点 
//vis :Y集合元素是否被访问过

void add(int x,int y){
    ++cnt;
    e[cnt].next = ihead[x];
    e[cnt].to = y;
    ihead[x] = cnt;
}
// 匈牙利算法
bool dfs(int x){
    for (int i = ihead[x]; i;i=e[i].next){
        int y = e[i].to;
        if(!vis[y]){
            vis[y] = true;
            if(mc[y] ==0 || dfs(mc[y])){
                mc[y] = x;
                return true;
            }
        }
    }
    return false; 
}
int getAnswer(int n, vector<vector<int>> board)
{
    /* 请在这里设计你的算法 */
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         if (board[i][j])
    //             car.push_back(node(i, j));
    // int locate = car.size();
    // int cnt = dfs1(0, locate);
    // return cnt;
    cnt = 0;
    for (int i = 1; i <= n * 2;++i){
        ihead[i] = 0;
        mc[i] = 0;
    }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;++j) 
            if(board[i-1][j-1])
                add(i, j + n);
    int ans = 0;
    for (int i = 1; i <= n;++i)
        if(ihead[i] == 0){
            memset(vis, 0, sizeof(bool) * (n * 2) + 1);
            if(dfs(i))
                ++ans;
        }
}

// ================= 代码实现结束 =================

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> e;
    for (int i = 0; i < n; ++i)
    {
        vector<int> t;
        for (int j = 0; j < n; ++j)
        {
            int x;
            scanf("%d", &x);
            t.push_back(x);
        }
        e.push_back(t);
    }
    printf("%d\n", getAnswer(n, e));
  
        return 0;
}
