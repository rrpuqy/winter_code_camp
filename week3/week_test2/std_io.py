#!/usr/bin/env pypy3

N = 1005

# ================= 代码实现开始 =================

# n, m：n 行 m 列
# a：二维数组，行列下标均从 0 开始
# 返回值：价值最大的“折”的价值
def get_answer(n, m, a):
    return 0

# ================= 代码实现结束 =================

from sys import stdin

n, m = map(int, stdin.readline().strip().split())
a = []

for i in range(n):
    a.append(list(map(int, stdin.readline().strip().split())))

print(get_answer(n, m, a))
