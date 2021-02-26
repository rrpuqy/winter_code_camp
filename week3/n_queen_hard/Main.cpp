#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 一个n×n的棋盘，在棋盘上摆n个皇后，求满足任意两个皇后不能在同一行、同一列或同一斜线上的方案数
// n：上述n
// 返回值：方案数
// n皇后回溯法
const int N = 16;
int a[N];
int ans, allOne;
void dfs(int pos,int left,int right)
{
	if(pos == allOne){
		++ans;
		return;
	}
	for(int t=allOne &(~(pos | left | right));t;){
		int p = t & -t;
		dfs(pos | p, (left | p) << 1, (right | p) >> 1);
		t ^= p;
	}
}

// bool judge(int r, int c)
// {
// 	for (int i = 0; i < r;i++){
// 		if(c==a[i] || r-i==c-a[i] || r+c == i+a[i])
// 			return false;
// 	}
// 	return true;
// }
// int dfs(int k,int n){
// 	if(k==n)
// 		return 1;
// 	int cnt = 0;
// 	for (int i = 0; i < n; i++)
// 		if(judge(k,i)){
// 			a[k] = i;
// 			cnt+=dfs(k + 1, n);
// 			a[k] = -1;
// 		}
// 	return cnt;
// }



int getAnswer(int n)
{
	/* 请在这里设计你的算法 */
	// memset(a, -1, sizeof a);
	// return dfs(0, n);
	ans = 0;
	allOne = (1 << n) - 1;
	dfs(0, 0, 0);
	return ans;
}

// ================= 代码实现结束 =================

int main() {
    int n;
	cin >> n;
	cout << getAnswer(n) << endl;
	return 0;
}
