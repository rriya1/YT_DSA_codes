#include<bits/stdc++.h>
#include<iostream> 
using namespace std;

int knapsack(vector<int> w,vector<int> val,int,int);

int main()
{
    int item_count;
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
    if(w[len-1]<=W)
        return max(val[len-1]+knapsack(w,val,W-w[len-1],len-1),knapsack(w,val,W,len-1));
    else 
    {
        if(w[len-1]>W)
            return knapsack(w,val,W,len-1);
    }
}
