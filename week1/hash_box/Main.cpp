#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

typedef long long ll;
const int Mod = 1e7+3;
vector<ll> table[Mod];
/* 请在这里定义你需要的全局变量 */

// 执行操作时会调用这个函数
int Hash(ll x){
    return x % Mod;
}
// op：对应该次操作的 op（具体请见题目描述）
// x：对应该次操作的 x（具体请见题目描述）
// 返回值：如果输出为"Succeeded"，则这个函数返回 1，否则返回 0
bool check(int op, ll x) {
    /* 请在这里设计你的算法 */
    int h = Hash(x);
    vector<ll>:: iterator ptr = table[h].end();
    for(vector<ll>::iterator it =table[h].begin();it!=table[h].end();++it){
        if(*it==x){
            ptr = it;
            break;
        }
    }
    if(op==1){
        if(ptr!=table[h].end()) return 0;
        else{
            table[h].push_back(x);
            return 1;
        }
    }
    else{
        if(ptr==table[h].end()) return 0;
        else{
            *ptr = table[h].back();
            table[h].pop_back();
            return 1;
        }
    }
}

// ================= 代码实现结束 =================

int main() {
    // int Q, op;
    // ll x;
    // scanf("%d", &Q);
    // while (Q--) {
    //     scanf("%d%lld", &op, &x);
    //     puts(check(op, x) ? "Succeeded" : "Failed");
    // }
    // return 0;
    cout<<Mod;
}
