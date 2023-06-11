//solved
#include<bits/stdc++.h>
using namespace std;

void sort_rec(vector<int>&);
void insert_rec(vector<int>&,int);

int main()
{
    vector<int> v;
    int size;
    int x;
    cout<<"enter size of vector: ";
    cin>>size;
    cout<<"enter the array: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"unsorted vector is: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }
    sort_rec(v);
    cout<<endl<<"Vector after sorting: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

void sort_rec(vector<int> &vec)
{
    if(vec.size()==1)
    {
        return;
    }
    int val =vec[vec.size()-1];
    vec.pop_back();
    sort_rec(vec);
    insert_rec(vec,val);
    //return vec;
}

void insert_rec(vector<int> &ve,int temp)
{
    if(ve.size()==0 || ve[ve.size()-1]<=temp)
    {
        ve.push_back(temp);
        return;
    }
    int val;
    val=ve[ve.size()-1];
    ve.pop_back();
    insert_rec(ve,temp);
    ve.push_back(val);
}