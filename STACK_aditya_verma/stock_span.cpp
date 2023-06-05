#include<bits/stdc++.h>
using namespace std;

vector<int> stock_span(vector<int>,int );

int main()
{
    int days;
    cout<<"Enter the number of days: ";
    cin>>days;
    vector<int> stock,SS;
    cout<<"Enter the stocks for "<<days<<": "<<endl;
    for(int i=0;i<days;i++)
    {
        int x;
        cin>>x;
        stock.push_back(x);
    }
    SS=stock_span(stock,days);
    cout<<"The stock span for each day is: "<<endl;
    for(int i=0;i<days;i++)
    {
        cout<<SS[i]<<" ";
    }
    return 0;
}

vector<int> stock_span(vector<int> v,int n)
{
    stack<pair<int,int>>s;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        while(!s.size()==0)
        {
            if(s.top().second>v[i])
            {
                a.push_back(s.top().first);
                break;
            }
            else
            {
                s.pop();
            }
        }//end of while loop
        if(s.size()==0)
        {
            a.push_back(-1);
        }
            s.push({i,v[i]});
    }//end of for loop
    for(int i=0;i<n;i++)
    {
        a[i]=i-a[i];
    }//end of for loop
    return a;
}