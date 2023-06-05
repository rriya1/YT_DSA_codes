#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int> &);
void print(stack<int>);
void insert(stack<int>&,int);

int main()
{
    stack<int> s;
    int size,x;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    cout<<"Input the stack: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        s.push(x);
    }
    cout<<"Before reversing stack: "<<endl;
    print(s);
    reverse(s);
    cout<<"After reversing stack: "<<endl;
    print(s);
    return 0;
}

void reverse(stack<int> &s)
{
    if(s.size()==1)
    {
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
    return;
}

void insert(stack<int>&s,int ele)
{
    if(s.size()==0)
    {
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,ele);
    s.push(temp);
    return;
}

void print(stack<int>s)
{
    if(s.size()==1)
    {
        cout<<s.top()<<endl;
        return;
    }
    cout<<s.top()<<endl;
    s.pop();
    print(s);
    return;
}