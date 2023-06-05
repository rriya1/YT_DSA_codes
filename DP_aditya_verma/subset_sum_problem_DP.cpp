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
    // bool l;
    // l=solve(v,0,sum,v.size());
    // if(l==true)
    // {
    //     cout<<"true"<<endl;
    // }
    // else
    // cout<<"false";

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

    // for(int i=0;i<n+1;i++)
    // {
    //     for(int j=0;j<sum+1;j++)
    //     {
    //             cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

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
    
    // for(int i=0;i<n+1;i++)
    // {
    //     for(int j=0;j<sum+1;j++)
    //     {
    //             cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    }

    cout<<"result: "<<t[n][sum];
    return 0;
}


//recursive function
// bool solve(vector <int> v,int n,int sum,int size)
// {
//     if(n==size && sum!=0)
//         return 0;
//     if(sum==0)
//         return 1;

//     int ans1=0,ans2=0,ans3=0;
//     if(v[n]<=sum)
//     {
//          ans1=solve(v,n+1,sum-v[n],size);
//          ans2=solve(v,n+1,sum,size);
//     }
//     else
//     {
//          ans3=solve(v,n+1,sum,size);
//     }

//     if(ans1 || ans2 || ans3)
//         return true;
//     else
//         return false;
// }