#!/usr/bin/env python3

# ================= 代码实现开始 =================

N = 100005

# Stack：栈
# top：栈顶位置
Stack = ['' for i in range(N)]
top = 0

# 压入栈顶
# name：被压入的人的姓名
def push(name):
    global top
    ''' 请在这里设计你的算法 '''

# 弹出栈顶
# 返回值：被弹出人的姓名
def pop():
    global top
    ''' 请在这里设计你的算法 '''

# 询问栈中某个位置上的人的姓名（栈底位置为1，向栈顶方向的位置依次递增）
# pos：询问的位置
# 返回值：pos位置上人的姓名
def query(pos):
    ''' 请在这里设计你的算法 '''

# ================= 代码实现结束 =================

n = int(input())
for _ in range(n):
    tmp = input().split(' ')
    op = int(tmp[0])
    if op == 1:
        name = tmp[1].strip('\n')
        push(name)
    elif op == 2:
        print(pop())
    else:
        pos = int(tmp[1])
        print(query(pos))

