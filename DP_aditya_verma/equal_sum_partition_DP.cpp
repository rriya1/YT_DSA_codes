#include<bits/stdc++.h>
using namespace std;

//bool solve(vector<int>,int,int,int);

int main()
{
    int n,sum;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v;
    cout<<"Enter the elemnts of the array:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
   

    int tsum=accumulate(v.begin(),v.end(),0);
    if(tsum%2==0)
    {
        sum=tsum/2;
        int t[n+1][sum+1];

        //initialization
        for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //base condition
            if(i==0)
            {
                t[i][j]=0;
            }
            
            if(j==0)
            {
                t[i][j]=1;
            }
            
        }
    }
 // printing initialized table
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
                cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

// doing DP and filling the table
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            
            if(v[i-1]<=j)
            {
                    t[i][j]=(t[i-1][j-v[i-1]] || t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];
        }
    }

cout<<endl;
    //printing the filled table
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
                cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
 // printing result
    cout<<"result: "<<t[n][sum];
    }
    
    else
    {
        cout<<"0";
    }

    
    return 0;
}