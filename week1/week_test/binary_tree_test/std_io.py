#!/usr/bin/env pypy3

# 二叉树的节点，包含左右孩子的编号（在数组中的下标），编号范围为 0 到 n-1，若编号为 -1，表示空
class Node:
    def __init__(self, l, r): # 边的两个端点为x和y，边权为w。若为关键边则t=1，否则t=0
        self.l = l
        self.r = r

# ================= 代码实现开始 =================

# n：二叉树节点个数
# a：二叉树 a 的节点数组，大小为 n
# b：二叉树 b 的节点数组，大小为 n
# 返回值：若二叉树 a 与 b 相等，则返回真，否则返回假
# 提示：
# 解释一下节点数组的意思，由于节点的编号在 0 到 n-1 的范围内
# 因此可以将这 n 个节点存储到一个数组里，那么二叉树 a 中编号
# 为 i 的节点就是 a[i]，其左孩子编号为 a[i].l，右孩子编号为 a[i].r
# a[i] 的左孩子为 a[a[i].l]，右孩子为 a[a[i].r]
# 一定要把编号与节点区分开来，同时还要注意编号为 -1 的情况，此时该孩子
# 为空，不能用 -1 去作为数组下标噢，越界了。
def get_answer(n, a, b):
    return True

# ================= 代码实现结束 =================

from sys import stdin

T = int(stdin.readline().strip())
while T > 0:
    T -= 1
    n = int(stdin.readline().strip())
    a, b = [], []
    for i in range(n):
        l, r = map(int, stdin.readline().strip().split())
        a.append(Node(l, r))
    for i in range(n):
        l, r = map(int, stdin.readline().strip().split())
        b.append(Node(l, r))
    print("yes" if get_answer(n, a, b) else "no")
