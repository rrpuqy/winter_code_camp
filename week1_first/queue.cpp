#include <bits/stdc++.h>

using namespace std;
const int cap_size = 2000;
class mystack
{
private:
    /* data */
    // char *a;
    string a[cap_size];
    // int size, cap;
    int front,end;
    // void increaseCap()
    // {
    //     cap *= 2;
    //     char *t = a;
    //     a = new char[cap];
    //     for (int i = 0; i < size; i++)
    //         a[i] = t[i];
    //     delete t;
    // }

public:
    mystack(/* args */);
    ~mystack();
    void enqueue(string ele);
    string dequeue();

    string getIndexOf(int index);
};

mystack::mystack(/* args */)
{
    // cap = cap_size;
    // a = new string[cap];
    // size = 0;
    front = end = 0;
}

mystack::~mystack()
{
    // delete a;
}
void mystack::enqueue(string ele)
{
    // if (size > cap - 15)
    //     increaseCap();
    // for (char &i : ele)
    // {
    //     a[size++] = i;
    // }
    if((end+1 % cap_size) != front){
        a[end] = ele;
        end = (end+1) %cap_size;
    }
        
}
string mystack::dequeue()
{
    if(front!=end){

        string t =  a[front];
        front =( front+1)%cap_size;
        return t;
    }
}
string mystack::getIndexOf(int index)
{
    int i = (front+index-1)%cap_size;
    string t = a[i];
    return t;
}
int main()
{
    int n;
    cin >> n;
    int op;
    string ele;
    int index;
    mystack s;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> ele;
            s.enqueue(ele);
        }
        else if (op == 2)
        {
            string re = s.dequeue();
            cout << re << endl;
        }

        else
        {
            cin >> index;
            string t = s.getIndexOf(index);
            cout << t << endl;
        }
    }
}
