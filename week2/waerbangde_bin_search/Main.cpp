#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 本函数传入数组 a 及所有询问，你需要求解所有询问并一并返回
// n：序列 a 的长度
// a：存储了序列 a
// Q：询问个数
// query：依次存储了所有询问的参数 x
// 返回值：一个 vector<int>，依次存放各询问的答案
int binary_search(vector<int> &a, int lo, int hi, int q)
{
    // if(lo>hi)
    //     return hi + 1;
    // a[lo-1]<q a[hi]<q a[hi+1]>=q

    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (a[mid] >= q)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return hi + 1;
}
vector<int> getAnswer(int n, vector<int> &a, int Q, vector<int> query)
{
    /* 请在这里设计你的算法 */
    sort(a.begin(), a.end());
    // for (int &i : a)
    //     cout << i << " ";
    // cout << endl;
    vector<int> ans;
    int ret;
    for (int &v : query)
    {
        // int v = query.front();
        // query.pop_back();
        // cout << "v:" << v << endl;
        ret = binary_search(a, 0, n - 1, v);
        ret == n ? ans.push_back(-1) : ans.push_back(a[ret]);
        // if()
    }
    return ans;
}

// ================= 代码实现结束 =================

int main()
{
    int n, Q, tmp;
    vector<int> a, query;
    a.clear();
    query.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d", &tmp);
        query.push_back(tmp);
    }
    vector<int> ans = getAnswer(n, a, Q, query);
    for (int i = 0; i < Q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
