#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int> &);
void print(stack<int>);
void insert_at_bottom(stack<int>&,int);

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
    int temp=s.top(); //the top element will get inserted at the bottom after stack gets reversed
    s.pop();
    reverse(s);
    insert_at_bottom(s,temp);
    return;
}

void insert_at_bottom(stack<int>&s,int ele)
{
    if(s.size()==0)
    {
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    insert_at_bottom(s,ele);
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