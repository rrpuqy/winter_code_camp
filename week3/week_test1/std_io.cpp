#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<short, ll> pil;
// ================= 代码实现开始 =================

// const ll N = 1e10;
// pil q[N];
// 注意，A和B都是长度为n的数组，下标从0开始
// 返回值：若存在合法，则返回true，否则返回false
pil trans(pil t, int k, vector<int> &a, vector<int> &b)
{
    if (k == 0)
        return pil(t.first + 1, t.second + a[t.first + 1]);
    else if (k == 1)
        return pil(t.first + 1, t.second + b[t.first + 1]);
    else if (k == 2)
        return pil(t.first + 1, t.second + ll(a[t.first + 1]) * b[t.first + 1]);
    else
        exit(1);
    }
bool getAnswer(int n, long long S, vector<int> A, vector<int> B)
{
    /* 请在这里设计你的算法 */
    // [0,mid],[mid+1,n-1]
    queue<pil> q;
    int mid = n / 2 -1;
    q.push(pil(-1, 0));
    vector<ll> ans1;
    vector<ll> ans2;

    while (!q.empty())
    {
        pil t = q.front();
        q.pop();
        if (t.first == mid)
        {
            ans1.push_back(t.second);
            continue;
        }
        for (int k = 0; k < 3; k++)
        {
            pil to = trans(t, k, A, B);
            q.push(to);
        }
    }
    q.push(pil(mid, 0));
    while (!q.empty())
    {
        pil t = q.front();
        q.pop();
        if (t.first == n-1)
        {
            ans2.push_back(t.second);
            continue;
        }
        for (int k = 0; k < 3; k++)
        {
            
            pil to = trans(t, k, A, B);
            q.push(to);
        }
    }
    sort(ans1.begin(), ans1.end());
    for (int i = 0; i < ans2.size();i++)
    {
        if(binary_search(ans1.begin(),ans1.end(),S-ans2[i]))
            return true;
    }
    return false;
    // for (ll &i : ans)
    //     if (i == S)
    //         return true;
    // return false;
}

// ================= 代码实现结束 =================

int main()
{
    int T;
    for (scanf("%d", &T); T--;)
    {
        int n;
        ll S;
        scanf("%d%lld", &n, &S);
        vector<int> t[2];
        for (int j = 0; j < 2; ++j)
            for (int i = 0, x; i < n; ++i)
            {
                scanf("%d", &x);
                t[j].push_back(x);
            }
        printf("%d\n", getAnswer(n, S, t[0], t[1]));
    }
    return 0;
}

// 其实是新建了一个数组c c中的元素与a,b中的元素相关
// 可以尝试用搜索算法 最后要记录的是元素的和 有用的就是位置信息
// 所以可以设计出状态 记录位置信息和元素和 直到位置达到终点看是否有元素和符合题意
// s的范围太大了 根本记录不下来啊 那就不用动态规划记录 直接用搜索中的队列 进行广度优先搜索 这样只需要用一个pair记录位置和总和就好
// int dfs(int i,int s){
//     if(i==-1&&s==0)
//         return 1;
//     if (i == -1 && s != 0)
//         return 0;
//     return dfs(i - 1, s - a[i]) | dfs(i - 1, s - b[i]) | dfs(i - 1, s - a[i] * b[i]);
// }
