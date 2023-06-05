#include<bits/stdc++.h>
using namespace std;

// int knapsack(vector<int>,vector<int>,int,int,int);
int knapsack(pair<int,int>[],int,int,int);

// bool comparePairs(const pair<int, int> &a,const pair<int, int> &b) 
// {
//   // Sort the pairs by the first element
//   return a.second < b.second;
// }

int main()
{
    int item_count;
    cout<<"Enter the number of items: ";
    cin>>item_count;
    pair<int,int> item[item_count];
    //vector<int> w,val;
    // cout<<"Enter the item weight: "<<endl;
    // for(int i=0;i<item_count;i++)
    // {
    //     int x;
    //     cin>>x;
    //     w.push_back(x);
    // }
    // cout<<"Enter the item value: "<<endl;
    // for(int i=0;i<item_count;i++)
    // {
    //     int x;
    //     cin>>x;
    //     val.push_back(x);
    // }

    cout<<"Enter the weight and value: "<<endl;
    for(int i=0;i<item_count;i++)
    {
        cin>>item[i].first;
        cin>>item[i].second;
    }

    cout<<"the item weight and value are: "<<endl;
    for(auto i : item)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Enter the max weight of the knapsack: ";
    int W;
    cin>>W;

    // sort(item,item+item_count,comparePairs);
    int profit=0;
    profit=knapsack(item,W,item_count,0);

    cout<<"The maximum profit is: "<<profit;
    return 0;
}

int knapsack(pair<int,int> item[],int W,int item_count,int pos)
{
    if(pos==item_count || W==0)
    {
        return 0;
    }

    int p;
    if(item[pos].first>W)
    {
        return knapsack(item,W,item_count,pos+1); ;
    }
    else
    {
        int profit1=knapsack(item,W,item_count,pos+1); //not including that item
        int profit2=item[pos].second+knapsack(item,W-item[pos].first,item_count,pos+1); //including the item, decreasing the max weight
        return max(profit1,profit2);
    }
    
}