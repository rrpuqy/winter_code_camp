const int n = 100;
int father[n];

int find(int x){
    if(father[x] == x)
        return x;
    father[x] = find(father[x]);
    return father[x];
}
int find1(int x){
    int p = father[x];
    if(p==x)
        return p;
    father[x] = find(p);
    return father[x];
}