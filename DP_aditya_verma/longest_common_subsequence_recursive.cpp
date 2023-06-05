#include<bits/stdc++.h>
using namespace std;

int LCS(string,string, int, int);

int main()
{
    string x,y;
    cout<<"Enter the string"<<endl;
    cout<<"FIRST: ";
    cin>>x;
    cout<<"SECOND:";
    cin>>y;
    int n=x.size();
    int m=y.size();
    cout<<"size: "<<n<<" "<<m<<endl;
    int s=LCS(x,y,n,m);
    cout<<"The longest common subsequence size is: "<<s;
    return 0;
}

int LCS(string x,string y,int n,int m)
{
    if(n==0 || m==0) //base condtion, string got finsihed or is null string, any of the 2 then the subsequence will also be a null string
    {
        return 0;
    }
    
    if(x[n-1]==y[n-1])
    {
        return 1+LCS(x,y,n-1,m-1);//the last string matches, so size of LCS increases by one and the length to be checked gets decreased for both the arrays
    }
    else
    {
        return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1)); //when the last string does not matches then we have 2 chaoices, we have totake max of the choices.
    }
}