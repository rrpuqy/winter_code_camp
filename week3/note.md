```c++
template<typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v,int & clock){
    dTime(v) = ++clock;status(v)=DISCOVERED;
    for(int u=firstNbr(v);-1<u;u=mextNbr(v,u))
    {
        switch(status(u)){
            case UNDISCOVERED:
                type(v,u)=Tree;
                parent(u) =v;
                DFS(u,clock);
                break;
            case DISCOVERED:
                type(v,u)=BACKWARD;
                break;
            default:
                type(v,u)=dTime(v)<dTime(u)?Forward:CROSS;
                break;
        }
    }
    status(v) = VISITED;fTime(v)=++clock;
}
```

```c++
int power(int a,int n){
    int pow = 1,p=a;
    while(0<n){
        if(n & 1) power*=p;
        n >>=1;
        p *=p;
    }
    return pow;
}
```
