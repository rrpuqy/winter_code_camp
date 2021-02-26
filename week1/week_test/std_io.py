#!/usr/bin/env pypy3

# ================ 代码实现开始 =================

# A：长度为n的数组，下标从0开始，为题中所给1到n的排列
# 返回值：返回一个长度为n的数组，表示所求序列
def getAnswer(n, A):
    ''' 请在这里设计你的算法 '''

# ================= 代码实现结束 =================

from sys import stdin, stdout

n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
stdout.write(' '.join(map(str, getAnswer(n, a))))
