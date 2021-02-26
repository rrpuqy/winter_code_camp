#!/usr/bin/env pypy3

# ================= 代码实现开始 =================

# 初始化函数，在操作开始前会调用一次
def init(n):
    pass

# x 是编号，范围为 1 到 n
# 若成功操作，返回 True，否则返回 False
def split_succ(x):
    return True

# x 是编号，范围为 1 到 n
# 若成功操作，返回 True，否则返回 False
def split_prev(x):
    return True

# x, y 是编号，范围为 1 到 n
# 若成功操作，返回 True，否则返回 False
def link(x, y):
    return True

# x 是编号，范围为 1 到 n
# 返回遍历得到的序列
def visit_succ(x):
    return []

# x 是编号，范围为 1 到 n
# 返回遍历得到的序列
def visit_prev(x):
    return []

# ================= 代码实现结束 =================

from sys import stdin

n, m = map(int, stdin.readline().strip().split())
init(n)

for i in range(m):
    line = stdin.readline().strip().split()
    op, x = line[0], int(line[1])
    if op == "split_succ":
        print("yes" if split_succ(x) else "no")
    elif op == "split_prev":
        print("yes" if split_prev(x) else "no")
    elif op == "link":
        y = int(line[2])
        print("yes" if link(x, y) else "no")
    elif op == "visit_succ":
        print(" ".join([str(i) for i in visit_succ(x)]))
    else:
        print(" ".join([str(i) for i in visit_prev(x)]))
