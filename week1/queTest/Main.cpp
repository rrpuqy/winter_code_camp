#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
// const int N = 100005;
const int N = 5;
string Queue[N];
int head, tail;
// 队尾入队
// name：入队人的姓名
void enqueue(string name)
{
    /* 请在这里设计你的算法 */
    // Queue[tail++] = name;
    // Queue[tail] = name;
    tail = tail + 1;
    if(tail == N)
        tail -= N;
    if(tail == head)
        exit(1);
}

// 队首出队
// 返回值：队首的姓名
string dequeue()
{
    /* 请在这里设计你的算法 */
    return Queue[head++];
    if(head == N)
        head -= N;
}

// 询问队列中某个位置上的人的姓名（队首位置为1，往后位置依次递增）
// pos：询问的位置
// 返回值：pos位置上人的姓名
string query(int pos)
{
    /* 请在这里设计你的算法 */
    return Queue[head + pos - 1];
}

// ================= 代码实现结束 =================

int main()
{
    int n;
    scanf("%d", &n);
    char name[20];
    for (; n--;)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%s", name);
            enqueue(name);
        }
        else if (op == 2)
        {
            printf("%s\n", dequeue().c_str());
        }
        else
        {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}
