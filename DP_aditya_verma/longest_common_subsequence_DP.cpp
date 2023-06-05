#include<bits/stdc++.h>
using namespace std;

int LCS(string,string, int, int);
int static t[101][101];//according to the constarint provided

int main()
{
    string x,y;
    //memset(t,-1,sizeof(t));//initialization of the table,can only be done in main if using memset
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
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            t[i][j]=0;
        }
    }
     
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
    {
         t[i][j]=1+t[i-1][j-1];//the last string matches, so size of LCS increases by one and the length to be checked gets decreased for both the arrays
    }
    else
    {
        t[i][j]=max(t[i-1][j],t[i][j-1]); //when the last string does not matches then we have 2 chaoices, we have totake max of the choices.
    }
        }
    
    }

    return t[n][m];
    
}