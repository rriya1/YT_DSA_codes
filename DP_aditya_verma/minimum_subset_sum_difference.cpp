#include<bits/stdc++.h>
using namespace std;

int min_diff(vector<int>);

int main()
{
    vector<int> s;
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push_back(x);
    }
    int diff=min_diff(s);
    cout<<"the minimum subset difference in the vector is: "<<diff;
    return 0;
}

int min_diff(vector<int> arr)
{
    int total1=accumulate(arr.begin(),arr.end(),0);
    int total=total1/2;
    cout<<total<<endl;
    //making all subset sums of the given array
    int size=arr.size();
    int t[size+1][total+1];
    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<total+1;j++)
        {
            if(i==0)
            t[i][j]=0;
            if(j==0)
            t[i][j]=1;
        }
    }
    
    //t[0][0]=1;
    for(int i=1;i<size+1;i++)
    {
        for(int j=0;j<total+1;j++)
        {
            if(arr[i-1]<=j)
            {
                if(t[i-1][j-arr[i-1]]==1 || t[i-1][j]==1)
                    t[i][j]=1;
                else
                    t[i][j]=0;
            }
            else
                t[i][j]=t[i-1][j];
        }
    }

    int k;
    //cout<<"last row"<<endl;
    //cout<<"size:"<<size<<endl;
    for(k=total;k>=0;--k)
    {
        //cout<<t[size][k]<<endl;
        if(t[size][k]==1)
            break;
    }
    //cout<<k<<endl;
    return total1-(2*k); //edit
}
