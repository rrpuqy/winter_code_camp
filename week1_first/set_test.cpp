#include<bits/stdc++.h>
using namespace std;

int main(){
    set <long long> s;
    int n;cin>>n;
    long long op,x;
    while(n--){
        cin>>op>>x;
        if(op==1){
            if(s.find(x)==s.end()){
                cout<<"Succeeded"<<endl;
                s.insert(x);
            }
            else
            {
                /* code */
                cout<<"Failed"<<endl;
            }
            
        }
        else
        {
            if(s.find(x)!=s.end()){
                s.erase(x);
                cout << "Succeeded" << endl;
            }
            else{
                cout << "Failed" << endl;
            }
        }
        
    }
}