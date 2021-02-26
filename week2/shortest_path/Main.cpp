#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================
typedef pair<int, int> pil;
/* 请在这里定义你需要的全局变量 */

// 这个函数用于计算答案（最短路）
// n：节点数目
// m：双向边数目
// U,V,W：分别存放各边的两端点、边权
// s,t：分别表示起点、重点
// 返回值：答案（即从 s 到 t 的最短路径长度）
const int N = 100005;
vector<pil> graph[N];
bool visited[N];
struct cmp{
    bool operator() (pil a,pil b){
        return a.second > b.second;
    }
};
int shortestPath(int n, int m, vector<int> U, vector<int> V, vector<int> W, int s, int t)
{
    /* 请在这里设计你的算法 */
    for (int i = 0; i < U.size(); i++)
    {
        int u = U[i], v = V[i], w = W[i];
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    vector<int> dist(n + 1, INT32_MAX);
    vector<int> index(n + 1);
    for (int i = 0; i < n; i++)
        index[i] = i + 1;
    int cnt = 0;
    dist[s] = 0;
    // swap(index[s],index[cnt++]);
    priority_queue<pil,vector<pil>,cmp> q;

    q.push(make_pair(s, 0));
    while (!q.empty())
    {
        pil c = q.top();
        q.pop();
        int cur_index = c.first;
        if (visited[cur_index])
            continue;
        // int dis = c.second;
        if (cur_index == t)
            break;
        // return dist[cur_index];
        for (int i = 0; i < graph[cur_index].size(); i++)
        {
            int to = graph[cur_index][i].first;
            int w = graph[cur_index][i].second;

            if (!visited[to] && dist[cur_index] + w < dist[to])
            {
                dist[to] = dist[cur_index] + w;
                q.push(make_pair(to, dist[to]));
            }
        }
    }
    return dist[t];

    //     while (cnt < n)
    //     {
    //         int index_min = cnt;
    //         for (int i = cnt+1; i <n; i++)
    //             if (dist[index[index_min]] > dist[index[i]])
    //                 index_min = i;
    //         swap(index[index_min], index[cnt]);
    //         if(index[cnt]==t)
    //             break;
    //         int cur_index = index[cnt];
    //         for (int i = 0; i < graph[cur_index].size(); i++)
    //         {
    //             int to = graph[cur_index][i].first;
    //             int w = graph[cur_index][i].second;
    //             dist[to] = min(dist[to], dist[cur_index] + w);
    //         }
    //         cnt++;
    //     }
    //     return dist[t];
}

// ================= 代码实现结束 =================

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    vector<int> U, V, W;
    U.clear();
    V.clear();
    W.clear();
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        U.push_back(u);
        V.push_back(v);
        W.push_back(w);
    }

    printf("%d\n", shortestPath(n, m, U, V, W, s, t));
    return 0;
}
