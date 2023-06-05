#include<bits/stdc++.h>
using namespace std;

void del(stack<int>&,int,int);
void print_stack(stack<int>&);

int main()
{
    stack<int> s;
    int size,x;
    cout<<"enter the size of the stack: ";
    cin>>size;
    cout<<"input the stack: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        s.push(x);
    }
    int pos;
    cout<<"Enter the position in the stack to be deleted: "<<endl;
    cin>>pos;
    cout<<"stack before the deletion: "<<endl;
    print_stack(s);
    int k=size-pos+1;
    del(s,pos,k);
    cout<<endl<<"stack after deletion: "<<endl;
    print_stack(s);
    return 0;
}

void print_stack(stack<int> &v)
{
    if(v.empty())
    {
        return;
    }
    int x=v.top();
    v.pop();
    cout<<x<<endl;
    print_stack(v);
    v.push(x);
}

void del(stack<int>&s,int index,int k)
{
    if(s.size()==k)
    {
        s.pop();
        return;
    }
    int val=s.top();
    s.pop();
    del(s,index-1,k);
    s.push(val);
}