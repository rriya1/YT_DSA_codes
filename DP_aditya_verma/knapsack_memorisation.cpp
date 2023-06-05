#include<bits/stdc++.h>
using namespace std;

int static t[102][102];
//memset(t,-1,sizeof(t));

int knapsack(vector<int>,vector<int>,int,int);

int main()
{
    int item_count;
    memset(t,-1,sizeof(t));
    cout<<"Enter the number of items: ";
    cin>>item_count;
    vector<int> w,val;
    cout<<"Enter the item weight: "<<endl;
    for(int i=0;i<item_count;i++)
    {
        int x;
        cin>>x;
        w.push_back(x);
    }
    cout<<"Enter the item value: "<<endl;
    for(int i=0;i<item_count;i++)
    {
        int x;
        cin>>x;
        val.push_back(x);
    }
    cout<<"Enter the max weight of the knapsack: ";
    int W;
    cin>>W;

    int profit=0;
    profit=knapsack(w,val,W,item_count);

    cout<<"The maximum profit is: "<<profit;
    return 0;
}

//recursive function

int knapsack(vector<int> w,vector<int> val,int W,int len)
{
    if(len==0 || W==0)
        return 0;
    if(t[len][W]!=-1)
    {
        return t[len][W];
    }
    if(w[len-1]<=W)
        return t[len][W]=max(val[len-1]+knapsack(w,val,W-w[len-1],len-1),knapsack(w,val,W,len-1));
    else 
    {
        //if(w[len-1]>W)
            return t[len][W]=knapsack(w,val,W,len-1);
    }
}
