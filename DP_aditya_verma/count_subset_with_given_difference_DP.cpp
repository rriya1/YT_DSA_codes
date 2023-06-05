#include<bits/stdc++.h>
using namespace std;

int diff_given(vector<int>,int);

int main()
{
    vector<int> s;
    cout<<"enter the number of elements: ";
    int n;cin>>n;
    cout<<"enter the numbers in the vector"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push_back(x);
    }

    int total=accumulate(s.begin(),s.end(),0);
    int diff;
    cout<<"enter the difference to be found: ";
    cin>>diff;
    int sub=(total+diff)/2;
    int count=diff_given(s,sub);
    //int sub2=total-sub1;
    cout<<"The subsets are: "<<count;
    return 0;
}

int diff_given(vector<int> s, int sub)
{
    int n=s.size();
    cout<<"n: "<<n<<endl<<"sub: "<<sub<<endl;
    int t[n+1][sub+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sub+1;j++)
        {
            if(i==0)
            t[i][j]=0;
            //(j==0)
            //[i][j]==1;
        }
    }
    
    t[0][0]=1;

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<sub+1;j++)
        {
            if(s[i-1]<=j)
            {
                    t[i][j]=t[i-1][j-s[i-1]] + t[i-1][j];
            }
            else
                t[i][j]=t[i-1][j];
        }
    }
    
    // int sum=0;
    // for(int i=0;i<sub+1;i++)
    // {
    //     if(t[n][i]==1)
    //     sum++;
    // }
    //cout<<sum;
    cout<<"result"<<t[n][sub]<<endl;
    return t[n][sub];
}