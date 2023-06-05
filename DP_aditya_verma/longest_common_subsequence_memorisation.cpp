#include<bits/stdc++.h>
using namespace std;

int LCS(string,string, int, int);
int static t[101][101];//according to the constarint provided

int main()
{
    string x,y;
    memset(t,-1,sizeof(t));//initialization of the table,can only be done in main if using memset
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
     
    if(t[m][n]!=0)
    {
        return t[m][n];
    }
    else
    {
    if(x[n-1]==y[n-1])
    {
        return  t[m][n]=1+LCS(x,y,n-1,m-1);//the last string matches, so size of LCS increases by one and the length to be checked gets decreased for both the arrays
    }
    else
    {
        return t[m][n]=max(LCS(x,y,n-1,m),LCS(x,y,n,m-1)); //when the last string does not matches then we have 2 chaoices, we have totake max of the choices.
    }
    }
    
}