#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

#define MAXN 5000

using namespace std;

char a[MAXN + 10], b[MAXN + 10];
int na, nb;
int dp[MAXN + 10][MAXN + 10];
int solve()
{
    // return 233;
    for (int i = 1; i <= na;i++)
        for (int j = 1; j <= nb;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[na][nb] * 4 + (min(na, nb) - dp[na][nb]) * 2 + abs(na - nb);
}

int main() {
    scanf("%d%s", &na, a + 1);
    scanf("%d%s", &nb, b + 1);
    printf("%d\n", solve());
    
    return 0;
}


// 碱基要插入到序列里面 最后两序列的长度肯定是一样长的
// 可以理解为求两个串的最长公共子序列，因为加长长度不会影响最后结果 （空对空为0）
// 最后结果为两个串的最长公共子序列长度*4+串长之差*2


// 长度为m的后缀 是从[n-m+1,n) n-(n-m+1) = m-1 长度 [2,5]
n = 5 m=2 n-m -= 3 [3,5)
5 -2 ,5-1,