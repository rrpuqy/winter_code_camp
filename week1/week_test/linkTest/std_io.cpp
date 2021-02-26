#include <iostream>
#include <vector>
using namespace std;
// 代码实现开始
const int N = 1005;

struct Node
{
    int pre, next;
    Node(int a, int b)
    {
        pre = a;
        next = b;
    }
};
vector<Node> my_list;
// 初始化函数，在操作开始前会调用一次
void init(int n)
{
    my_list.assign(n + 1, Node(0, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     my_list.push_back(Node(0, 0));
    // }
}

// x 是编号，范围为 1 到 n
// 若成功操作，返回 true，否则返回 false
bool split_succ(int x)
{
    if (my_list[x].next)
    {
        int t = my_list[x].next;
        my_list[t].pre = 0;
        my_list[x].next = 0;
        return true;
    }
    return false;
}

// x 是编号，范围为 1 到 n
// 若成功操作，返回 true，否则返回 false
bool split_prev(int x)
{
    if (my_list[x].pre)
    {
        int t = my_list[x].pre;
        my_list[x].pre = 0;
        my_list[t].next = 0;
        return true;
    }
    return false;
}

// x, y 是编号，范围为 1 到 n
// 若成功操作，返回 true，否则返回 false
bool link(int x, int y)
{
    if(!my_list[x].next && !my_list[y].pre){
        my_list[x].next = y;
        my_list[y].pre = x;
        return true;
    }
    return false;
}

// x 是编号，范围为 1 到 n
// 返回遍历得到的序列
std::vector<int> visit_succ(int x)
{
    std::vector<int> ans;
    ans.push_back(x);
    int af = my_list[x].next;
    while (af && af!=x){
        ans.push_back(af);
        af = my_list[af].next;
    }
        return ans;
}

// x 是编号，范围为 1 到 n
// 返回遍历得到的序列
std::vector<int> visit_prev(int x)
{
    std::vector<int> ans;
    ans.push_back(x);
    int bf = my_list[x].pre;
    while (bf && bf != x)
    {
        ans.push_back(bf);
        bf = my_list[bf].pre;
    }
    return ans;
}

// 代码实现结束

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, x, y;
    std::string op;
    std::cin >> n >> m;
    init(n);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> op >> x;
        if (op == "split_succ")
        {
            std::cout << (split_succ(x) ? "yes" : "no") << '\n';
        }
        else if (op == "split_prev")
        {
            std::cout << (split_prev(x) ? "yes" : "no") << '\n';
        }
        else if (op == "link")
        {
            std::cin >> y;
            std::cout << (link(x, y) ? "yes" : "no") << '\n';
        }
        else if (op == "visit_succ")
        {
            std::vector<int> ans = visit_succ(x);
            for (int i = 0; i < ans.size(); i++)
            {
                std::cout << ans[i] << " \n"[i + 1 == ans.size()];
            }
        }
        else
        {
            std::vector<int> ans = visit_prev(x);
            for (int i = 0; i < ans.size(); i++)
            {
                std::cout << ans[i] << " \n"[i + 1 == ans.size()];
            }
        }
    }
    return 0;
}
