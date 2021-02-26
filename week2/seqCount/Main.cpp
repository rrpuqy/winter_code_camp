#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 求出有多少个a数组中的连续子序列（长度大于1），满足该子序列的最大值最小值之差不大于d
// n：a数组的长度
// d：所给d
// a：数组a，长度为n
// 返回值：满足条件的连续子序列的个数
ll getCount(vector<int> a, int lo, int hi, int d)
{
    if (lo == hi - 1){
        if(abs(a[lo]-a[hi]) <=d)
            return 1;
        else
            return 0;
    }

    if (lo == hi)
        return 0;
    int mid = (lo + hi) / 2;
    // ll t1 = getCount(a, lo, mid - 1, d);
    // cout << t1 << endl;
    // ll t2 = getCount(a, mid + 1, hi, d);
    // cout << t2 << endl;
    // int tmin = mid, tmax = mid;
    int l = lo;
    ll cnt = 0;
    stack<int> tmax;
    stack<int> tmin;
    tmax.push(mid);
    tmin.push(mid);
    for (int i = mid - 1; i >= lo; i--)
    {
        if (a[i] > a[tmax.top()])
        {
            if (a[i] - a[tmin.top()] <= d)
                tmax.push(i);
            else
            {
                l = i+1;
                break;
            }
        }
        else if (a[i] < a[tmin.top()])
        {
            if (a[tmax.top()] - a[i] <= d)
                tmin.push(i);
            else
            {
                l = i+1;
                break;
            }
        }
    }
    int l_long = mid -  l;
    cnt += l_long;
    // int rmax = tmax.top();
    // tmax.pop();
    // int rmin = tmin.top();
    // tmin.pop();
    // while(!tmax.empty()){
    //     cout << tmax.top()<< " ";
    //     tmax.pop();
    // }
    // cout << endl;
    // while (!tmin.empty())
    // {
    //     cout << tmin.top()<< " ";
    //     tmin.pop();
    // }
    // return 0;
    int frmax = 0, frmin = 0;
    for (int i = mid + 1; i <= hi; i++)
    {
        if (a[i] > a[tmax.top()])
        {
            // {
            //     if (a[i] - a[tmin.top()] <= d)
            //     {
            //         rmax = i;
            //         frmax = 1;
            //     }
            // else
            // {
            //     // cnt += (i - 1 - mid) * (mid - l - 1) + (i - 1 - id);
            //     if(!frmin){
            //         while()
            //     }
            // }
            // if (a[i] - a[tmin.top()] <= d)
            // {
            // }
            tmax.push(i);
            frmax = 1;
            if (a[i] - a[tmin.top()] > d)
            {
                if (frmin)
                    break;
                if (!frmin)
                {
                    while (!tmin.empty() && a[i] - a[tmin.top()] > d)
                        tmin.pop();
                    if (tmin.empty())
                        break;
                    else
                    {
                        l = max(l, tmin.top());
                        // cnt += 1 + mid - l;
                    }
                }
            }
        }
        else if (a[i] < a[tmin.top()])
        {
            tmin.push(i);
            frmin = 1;
            if (a[tmax.top()] - a[i] > d)
            {
                if (frmax)
                    break;
                while (!tmax.empty() && a[tmax.top()] - a[i] > d)
                    tmax.pop();
                if (tmax.empty())
                    break;
                else
                {
                    l = max(l, tmax.top());
                }
            }
        }
        cout << l << " ";
        cnt += 1 + mid - l;
    }
    // return cnt+t1+t2;
    return cnt;
}
const int N = 300005;
int n, d, max_value[N], min_value[N];
vector<int> a;
long long solve(int l,int r){
    if(l==r)
        return 0;
    int mid = (l + r) / 2;
    long long ans = solve(l, mid) + solve(mid + 1, r);
    for (int i = mid + 1; i <= r;i++){
        min_value[i] = (i == mid + 1) ? a[i] : min(min_value[i - 1], a[i]);
        max_value[i] = (i == mid + 1) ? a[i] : max(max_value[i - 1], a[i]);

    }
    int mn = 0, mx = 0, pos = r;
    for (int i = mid; i >= l && pos > mid;--i){
        mn = (i == mid) ? a[i] : min(mn, a[i]);
        mx = (i == mid ) ? a[i] : max(mx, a[i]);
        for (; pos > mid && max(mx, max_value[pos]) - min(mn, min_value[pos]) > d; --pos)
            ;
        ans += pos - mid;
    }
    return ans;
}
long long getAnswer(int n, int d, vector<int> a)
{
    
    
    /* 请在这里设计你的算法 */
    // return getCount(a, 0, n - 1, d);
    ::n = n;
    ::d = d;
    ::a = a;
    return solve(0, n - 1);
}

// ================= 代6码实现结束 =================

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%lld\n", getAnswer(n, d, a));
    return 0;
}

// 9 6 5 9 4 3 6 8 2 10 4