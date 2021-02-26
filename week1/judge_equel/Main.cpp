#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 给定n个变量以及m个约束，判定是否能找出一种赋值方案满足这m个约束条件
// n：如题意
// m：如题意
// A：大小为m的数组，表示m条约束中的a
// B：大小为m的数组，表示m条约束中的b
// E：大小为m的数组，表示m条约束中的e
// 返回值：若能找出一种方案，返回"Yes"；否则返回"No"（不包括引号）。

// 思路应该是使用并查集  相等的话就将两个元素所在的并查集合并，
// 不相等的话 如果两个元素在一个并查集里面就错误，否则分别建立新的并查集。
int find(vector<int> &a,int i){
    int t = i;
    int p = a[t];
    while(p!=0){
        t = p;
        p = a[t];
    }
    return t;
}
void merge(vector<int> &a,int i,int j){
    int p1 = find(a,i);
    int p2 = find(a,j);
    if(p1!=p2){
        a[p2] = p1;
    }
}
string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {
    /* 请在这里设计你的算法 */
    // int flag = 1;
    vector<int> uni(n+1,0);
    for(int i=0;i<m;i++){
        if(E[i]==1){
            merge(uni,A[i],B[i]);
        }
    }
    for(int i=0;i<m;i++){
        if(E[i]==0){
            if(find(uni,A[i])==find(uni,B[i])){
                return "No";
            }
        }
    }
    return "Yes";
}

// ================= 代码实现结束 =================

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> A, B, E;
        for (int i = 0; i < m; ++i) {
            int a, b, e;
            scanf("%d%d%d", &a, &b, &e);
            A.push_back(a);
            B.push_back(b);
            E.push_back(e);
        }
        printf("%s\n", getAnswer(n, m, A, B, E).c_str());
    }
    return 0;
}
