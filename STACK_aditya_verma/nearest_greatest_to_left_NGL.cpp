#include<bits/stdc++.h>
using namespace std;

void  NGL(vector<int>,vector<int>&);

int main()
{
    vector<int> v,v1;
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    NGL(v,v1);
    cout<<"The resultant array: "<<endl;
    for(int i=0;i<=n-1;i++)
    {
        cout<<v1[i]<<endl;
    }
    return 0;
}

void NGL(vector<int>s,vector<int>&s1)
{
    stack<int> s2;
    for(int i=0;i<s.size();i++)
    {
        while(!s2.size()==0)
        {
            if(s2.top()<=s[i])
            {
                s2.pop();
            }
            else
            {
                s1.push_back(s2.top());
                break;
            }
        }
        if(s2.size()==0)
        {
            s1.push_back(-1);
        }
        s2.push(s[i]);
    }
}

