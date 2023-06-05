#include<bits/stdc++.h>
using namespace std;

void solve(int,int,int,string out,vector<string>&);

int main()
{
    cout<<"Enter an integer: ";
    int n;
    cin>>n;
    int one=0; int zero=0;
    vector<string> s;
    string out="";
    solve(one,zero,n,out,s);
    int i=1;
    cout<<"\nAll the n bit prefixes with #1>=#0 are: "<<endl;
    for(auto value : s)
    {
        cout<<i<<". "<<value<<endl;
        i++;
    }
    return 0;
}

void solve(int one,int zero, int n,string out,vector<string> &s)
{
    if(n==0)
    {
        s.push_back(out);
        return;
    }
    if(one>zero)
    {
        string out1,out2;
        out1=out;
        out2=out;
       // out1.push_back('1');
        out2.push_back('0');
        //solve(one+1,zero,n-1,out1,s);
        solve(one,zero+1,n-1,out2,s);
    }
    //if(one==zero)
    {
        string out3=out;
        out3.push_back('1');
        solve(one+1,zero,n-1,out3,s);
    }
    return;
}