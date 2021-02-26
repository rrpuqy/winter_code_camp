#include <bits/stdc++.h>

using namespace std;
const int cap_size = 2000;
class mystack
{
private:
    /* data */
    // char *a;
    string a[cap_size];
    int size, cap;
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
    void push(string ele);
    string pop();

    string getIndexOf(int index);
};

mystack::mystack(/* args */)
{
    cap = cap_size;
    // a = new string[cap];
    size = 0;
}

mystack::~mystack()
{
    // delete a;
}
void mystack::push(string ele)
{
    // if (size > cap - 15)
    //     increaseCap();
    // for (char &i : ele)
    // {
    //     a[size++] = i;
    // }
    a[size++] = ele;
}
string mystack::pop()
{
    return a[--size];
}
string mystack::getIndexOf(int index)
{
    return a[index - 1];
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
            s.push(ele);
        }
        else if (op == 2){
            string re = s.pop();
            cout<<re<<endl;
        }
            
        else
        {
            cin >> index;
            cout << s.getIndexOf(index) << endl;
        }
    }
}
