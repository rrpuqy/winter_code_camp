#!/usr/bin/env pypy3

# ================ 代码实现开始 =================

# 注意，A和B都是长度为n的数组，下标从0开始
# 返回值：若存在合法，则返回True，否则返回False
def getAnswer(n, S, A, B):
    ''' 请在这里设计你的算法 '''

# ================= 代码实现结束 =================

T = int(input())
for _ in range(T):
    n, S = map(int, input().split())
    t = [[], []]
    for j in range(2):
        t[j] = list(map(int, input().split()))
    print(int(getAnswer(n, S, t[0], t[1])))
