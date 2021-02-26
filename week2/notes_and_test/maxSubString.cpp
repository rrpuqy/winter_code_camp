#include<bits/stdc++.h>
using namespace std;

vector<int> seq;
int getMax(int lo,int hi)
{
    if(lo==hi)
        return seq[lo];
    int mid = (lo + hi) / 2;
    int s1 = getMax(lo, mid);
    int s2 = getMax(mid + 1, hi);
    int bestl = 0, bestr = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = mid, j = mid + 1; i >= lo, j <= hi;i--,j++){
        cnt1 += seq[i];
        cnt2 += seq[j];
        if(cnt1 >bestl)
            bestl = cnt1;
        if(cnt2 >bestr)
            bestr = cnt2;
    }
    return max({s1,s2,bestl+bestr});
}
int main(){
    int n,t;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> t;
        seq.push_back(t);
    }
    int ret = getMax(0, n - 1);
    cout << ret;
}