//solved
#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&s,int temp)
{
    if(s.empty() || s.top()<=temp)
    {
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;

}

void sort(stack<int>&s)
{
    if(s.size()==1)
        return;
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
    return;
}

int main()
{
    int n;
    stack<int> s;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        s.push(x);
    }

    sort(s);

     while(!s.empty())
    {
        int x=s.top();
        cout<<x<<" ";
        s.pop();
    }
}