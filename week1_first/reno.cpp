#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
class treeNode
{
private:
    /* data */

public:
    ll weight;
    int type;
    treeNode *left, *right;

    treeNode(ll wt);
    treeNode();
    ~treeNode();
};

treeNode::treeNode(ll wt)
{
    weight = wt;
    left = right = nullptr;
    type = 1;
}
treeNode::treeNode()
{
    weight = 0;
    type = 0;
    left = right = nullptr;
}
treeNode::~treeNode()
{
}

// vector<int> wt(1000);
ll n;
struct cmp
{
    bool operator ()(treeNode *a, treeNode *b)
    {
        return a->weight >= b->weight;
    }
};

priority_queue<treeNode *, vector<treeNode *>, cmp> wt;

int count(treeNode *p, int len)
{
    if (p->left)
    {
        return count(p->left, len + 1) + count(p->right, len + 1);
    }
    else return p->weight * len;
}
int main()
{
    cin >> n;
    while (n--)
    {
        ll t;
        cin >> t;
        wt.push(new treeNode(t));
    }
    ll sum = 0;
    while (wt.size() >= 2)
    {
        treeNode *t1 = (wt.top());
        wt.pop();
        treeNode *t2 = (wt.top());
        wt.pop();
        treeNode *p = new treeNode;
        p->left = t1;
        p->right = t2;
        p->weight = t1->weight + t2->weight;
        sum+=p->weight;
        wt.push(p);
    }
    treeNode *c = wt.top();
    // int ret = count(c, 0);
    cout << sum << endl;
}