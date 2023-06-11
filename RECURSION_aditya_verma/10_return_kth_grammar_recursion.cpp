//solved
#include<bits/stdc++.h>
using namespace std;

int solve(int,int);

int main()
{
    int n,k;
    cout<<"Enter the value of n and k: "<<endl;
    cin>>n>>k;
    if(k>pow(2,n-1))
    {
        cout<<"Wrong input values of k and n";
        return 0;
    }
    int value=solve(n,k);
    cout<<"The value at the position in the grammar is: "<<value;
    return 0;
}

int solve(int n,int k)
{
    //cout<<"solve"<<endl;
    if(n==1 && k==1)
    {
       // cout<<"BC";
        return 0;
    }
    int mid=pow(2,n-1)/2;
    int val;
    if(k<=mid)
    {
        return solve(n-1,k);
    }
    if(k>mid)
    {
        val=solve(n-1,k-mid);
        if(val==1)
            return 0;
        if(val==0)
            return 1;
    }
}