#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>,int,int,int);

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
    cout<<"Enter the sum: ";
    cin>>sum;
    int t[n+1][sum+1];
 

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //base condition
            if(i==0)
            {
                t[i][j]=0;
            }
        }
    }
    t[0][0]=1; //change
//printing initialized table
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++) 
        {
                cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++) //change 
        {
            
            if(v[i-1]<=j)
            {
                    t[i][j]=t[i-1][j-v[i-1]] + t[i-1][j];//change
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
cout<<endl;
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
                cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"result: "<<t[n][sum];
    return 0;
}
