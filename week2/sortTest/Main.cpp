#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
vector<int> a;
// 将给定数组a升序排序
// n：数组大小
// a：所给数组，大小为n
// 返回值：排序后的数组
void merge_sort(int lo, int hi)
{
    if (lo == hi)
        return;
    int mid = (lo + hi) / 2;
    merge_sort(lo, mid);
    merge_sort(mid + 1, hi);
    int p1 = lo;
    int p2 = mid + 1;
    vector<int> tmp;
    while (p1 <= mid && p2 <= hi)
    {
      if(a[p1]<=a[p2]){
          tmp.push_back(a[p1]);
          p1++;
      }
      else{
          tmp.push_back(a[p2]);
          p2++;
      }
    }
    while(p1<=mid){
        tmp.push_back(a[p1]);
        p1++;
    }
    while (p2 <= hi)
    {
        tmp.push_back(a[p2]);
        p2++;
    }
    // cout << (tmp.size() == hi - lo + 1)<<endl;
    int pt = 0;
    for (int i = lo; i <= hi; i++)
        a[i] = tmp[pt++];
}
void getAnswer(int n)
{
    /* 请在这里设计你的算法 */
    merge_sort(0, n - 1);
}

// ================= 代码实现结束 =================

int main()
{
    int n;
    scanf("%d", &n);
  
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    // for (int i = 0; i < n; ++i)
    //     printf("%d%c", a[i], " \n"[i == n - 1]);
    getAnswer(n);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}
