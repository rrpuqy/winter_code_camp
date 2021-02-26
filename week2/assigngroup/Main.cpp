#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 将所给数组分成连续的m份，使得数字之和最大的那一份的数字之和最小
// n：数组大小
// m：题中的m
// a：所给数组，大小为n
// 返回值：最优方案中，数字之和最大的那一份的数字之和

// 是一种划分 减而治之的思路来做 寻找当前划分最最值 和剩下划分最大值之间的最大值
// 划分的分数呢？ 分数越多越好 要使得每一份尽可能的均匀 大小一致 贪心的话？
// 因为是相邻 所以可以采用合并的方法 如果当前合并不会使得当前划分下的最大和增大 就可以合并
bool assign_test(vector<int> a,int part,ll largest){
    ll cnt = 0;
    int parts = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(cnt+a[i]<=largest)
            cnt += a[i];
        else{
            parts++;
            cnt = a[i];
        }
    }
    parts++;
    if(parts>part)
        return false;
    else
        return true;
}
bool check(long long d,int n,int m,vector<int> &a){
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < n;i++){
        if(a[i]>d)
            return false;
        sum += a[i];
        if(sum > d){
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= m;
}
long long getAnswer(int n, int m, vector<int> a)
{
    /* 请在这里设计你的算法 */
    int part_size = n;
    vector<int> part;
    // for (int i = 0; i < n; i++)
    //     a.push_back(a[i]);
    ll part_max = 0;
    ll bound_max = 0;
    for (int i = 0; i < part_size; i++)
    {
        if (a[i] > part_max)
            part_max = a[i];
        bound_max += a[i];
    }
    int bound_min = part_max;
    int cnt = 0;
    // int p = 0;

    // for (int i = 0; i < part_size; i++)
    // {
    //     if (cnt + a[i] <= part_max)
    //         cnt += a[i];
    //     else
    //     {
    //         part.push_back(cnt);
    //         cnt = a[i];
    //     }
    // }
    // part.push_back(cnt);
    // part_size = part.size();
   
   // boundmin <=ans <=boundmax 一定满足这个条件 我的写法
   // reference  solution  boundmin<=ans boundmax+1>=ans
   // 只有左右两边交错后才能得到正确答案 即boundmin = boundmax+1 = ans

    while(bound_min<bound_max){
        ll mid = (bound_max + bound_min) / 2;
        if(assign_test(a,m,mid)) bound_max=mid;
        else
            bound_min = mid + 1;
    }
    return bound_min;
}

// ================= 代码实现结束 =================

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%lld\n", getAnswer(n, m, a));
    return 0;
}
