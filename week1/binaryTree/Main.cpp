#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 给定一个1到n的排列，依次插入到二叉树中，返回前序遍历和后序遍历
// n：如题意
// sequence：给定的排列，大小为n
// 返回值：将要输出的元素依次加入到返回值中
const int N = 100005;
struct Node
{
    int val, l, r;
} Tree[N];

int cnt = 0;
// l,r 等于0 意味着 左右子树为空 即没有左右子树
// 返回的是下标
int insert(int num, int index)
{
    if (index == 0 )
    {

        cnt++;
        index = cnt;
        Tree[cnt].val = num;
        return index;
    }
    // int lt = Tree[index].l;
    // int rt = Tree[index].r;

    else if (Tree[index].val > num)
    {
         Tree[index].l = insert(num, Tree[index].l);
    }
    else
    {
        Tree[index].r = insert(num, Tree[index].r);
    }
    return index;
}
void mlr(vector<int> &seq, int index)
{
    seq.push_back(Tree[index].val);
    if (Tree[index].l)
        mlr(seq, Tree[index].l);
    if (Tree[index].r)
        mlr(seq, Tree[index].r);
}
void lrm(vector<int> &seq, int index)
{
    if (Tree[index].l)
        lrm(seq, Tree[index].l);

    if (Tree[index].r)
        lrm(seq, Tree[index].r);
    seq.push_back(Tree[index].val);
}
vector<int> getAnswer(int n, vector<int> sequence)
{
    /* 请在这里设计你的算法 */
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        root = insert(sequence[i], root);
    }
    vector<int> ans;
    mlr(ans, root);
    lrm(ans, root);
    return ans;
}

// ================= 代码实现结束 =================

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> sequence;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        sequence.push_back(x);
    }
    vector<int> ans = getAnswer(n, sequence);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[n + i], " \n"[i == n - 1]);
    return 0;
}
