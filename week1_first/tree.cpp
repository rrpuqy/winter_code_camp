#include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int ele;
        treeNode* left;
        treeNode* right;
        treeNode(int num){
            ele = num;
            left = nullptr;
            right = nullptr;
        }
};
class tree
{
private:
    /* data */
    treeNode * root;
public:
    tree(/* args */);
    ~tree();
    void insert(int num){
        treeNode * t= root;
        if(t==nullptr) root=new treeNode(num);
        return;
        // treeNode *p = root;
        while(true){
            // p = t;
            if(num<=t->ele){
                if(t->left)
                    t=t->left;
                else
                {
                     t->left = new treeNode(num);
                     break;
                }
            }   
            else
            {
                if(t->right) t=t->right;
                else
                {
                    t->right=new treeNode(num);
                    break;
                }
                
            }           
        }

    }
    void travel11(treeNode *t){
        cout<<t->ele<<" ";
        if (t->left)
            travel11(t->left);
        if (t->right)
            travel11(t->right);
    }
    void travel1_gen(){
        cout<<root->ele<<" ";
        if(root->left) travel11(root->left);
        if(root->right) travel11(root->right);
    }
    void travel22(treeNode* t){
        if (t->left)
            travel11(t->left);
        
        if (t->right)
            travel11(t->right);
        cout<<t->ele<<" ";
    }
    void travel2_gen(){
       if(root->left) travel22(root->left);
      
       if(root->right) travel22(root->right); 
       cout<<root->ele<<" ";
    }
};

tree::tree(/* args */)
{
    root = nullptr;
}

tree::~tree()
{
}

int main(){
    int n;cin>>n;
    tree p;
    while(n--){
        int num;cin>>num;
        p.insert(num);
    }
    p.travel1_gen();
    cout<<endl;
    p.travel2_gen();
}