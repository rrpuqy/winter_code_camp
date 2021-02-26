#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

// A：长度为n的数组，下标从0开始，为题中所给1到n的排列
// 返回值：返回一个长度为n的数组，表示所求序列
vector<int> getAnswer(int n, vector<int> A)
{
    /* 请在这里设计你的算法 */
    int maxOut = n;
    int st = 0;
    int end = 0;
    vector<int> ans;
    vector<int> index(n + 1, 0);
    vector<int> que(n);
    for (int i = 0; i < n; i++)
    {
        if (A[i] == maxOut)
        {
            // maxOut = 0;
            int maxOut_copy = maxOut;
            ans.push_back(A[i]);
            maxOut = 0;
            // for (int j = i + 1; j < n; j++)
            // {
            //     if (A[j] > maxOut)
            //         maxOut = A[j];
            // }
            for (int j = maxOut_copy - 1; j >= 1; j--)
            {
                if (index[j] == 0)
                {
                    maxOut = j;
                    break;
                }
            }
            while (true)
            {
                if (st == end || que[st] < maxOut && que[end - 1] < maxOut)
                    break;
                else if (que[st] >= que[end - 1] && que[st] > maxOut)
                {
                    ans.push_back(que[st++]);
                }

                else if (que[end - 1] >= que[st] && que[end - 1] > maxOut)
                    ans.push_back(que[--end]);
            }
        }
        else
        {
            que[end++] = A[i];
            index[A[i]] = 1;
        }
    }
    return ans;
}

// 蛮力的想法 每一次出队都应该是未出队元素中能出队的最大元素 贪心的思想
// 该元素一定是已经入队元素中能出队的元素 与未入队元素中的最大值之间   的最大值

// ================= 代码实现结束 =================

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        a.push_back(x);
    }
    vector<int> ans = getAnswer(n, a);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i - 1], " \n"[i == n]);
    return 0;
}
