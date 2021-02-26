#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// 二叉树的节点，包含左右孩子的编号（在数组中的下标），编号范围为 0 到 n-1，若编号为 -1，表示空
struct Node
{
    int l; // 表示左节点的编号
    int r; // 表示右节点的编号
};

// ================= 代码实现开始 =================

// n：二叉树节点个数
// a：二叉树 a 的节点数组，大小为 n
// b：二叉树 b 的节点数组，大小为 n
// 返回值：若二叉树 a 与 b 相等，则返回真，否则返回假
// 提示：
// 解释一下节点数组的意思，由于节点的编号在 0 到 n-1 的范围内
// 因此可以将这 n 个节点存储到一个数组里，那么二叉树 a 中编号
// 为 i 的节点就是 a[i]，其左孩子编号为 a[i].l，右孩子编号为 a[i].r
// a[i] 的左孩子为 a[a[i].l]，右孩子为 a[a[i].r]
// 一定要把编号与节点区分开来，同时还要注意编号为 -1 的情况，此时该孩子
// 为空，不能用 -1 去作为数组下标噢，越界了。
bool sub_answer(vector<Node> a, vector<Node> b, int rootA, int rootB)
{
    if (rootA == -1 && rootB == -1)
        return true;
    // else
    //     cout << "error";
    int la = a[rootA].l;
    int ra = a[rootA].r;
    int lb = b[rootB].l;
    int rb = b[rootB].r;
    // if(la==-1 && lb==-1 || la !=-1 && lb!= -1)
    if (la == -1 && lb != -1 || lb == -1 && la != -1 || ra == -1 && rb != -1 || ra != -1 && rb == -1)
        return false;
    else
    {
        return sub_answer(a, b, la, lb) && sub_answer(a, b, ra, rb);
    }
}
bool get_answer(int n, vector<Node> a, vector<Node> b)
{
    //     return sub_answer(a, b, 0, 0);
    queue <int> qa, qb;

    qa.push(0);
    qb.push(0);
    while (!qa.empty())
    {
        int rootA = qa.front();
        qa.pop();
        int rootB = qb.front();
        qb.pop();
        if (rootA == -1 && rootB == -1)
            continue;
        int la = a[rootA].l;
        int ra = a[rootA].r;
        int lb = b[rootB].l;
        int rb = b[rootB].r;
        if (la == -1 && lb != -1 || lb == -1 && la != -1 || ra == -1 && rb != -1 || ra != -1 && rb == -1)
            return false;
        else{
            qa.push(la);
            qa.push(ra);
            qb.push(lb);
            qb.push(rb);
        }
    }
    return true;
}

// ================= 代码实现结束 =================

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        vector<Node> a, b;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            a.push_back((Node){l, r});
        }
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            b.push_back((Node){l, r});
        }

        cout << (get_answer(n, a, b) ? "yes" : "no") << '\n';
    }

    return 0;
}