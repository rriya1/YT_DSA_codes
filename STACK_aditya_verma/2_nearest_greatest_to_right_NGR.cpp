#include<bits/stdc++.h>
using namespace std;

void  NGR(vector<int>,vector<int>&);

int main()
{
    vector<int> v,v1;
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    NGR(v,v1);
    cout<<"The resultant array: "<<endl;
    for(int i=n-1;i>=0;i--)
    {
        cout<<v1[i]<<endl;
    }
    return 0;
}

void NGR(vector<int>s,vector<int>&s1)
{
    stack<int> s2;
    for(int i=s.size()-1;i>=0;i--)
    {
        while(!s2.size()==0)
        {
            if(s2.top()<=s[i])
            {
                s2.pop();
            }
            else
            {
                s1.push_back(s2.top());
                break;
            }
        }
        if(s2.size()==0)
        {
            s1.push_back(-1);
        }
        s2.push(s[i]);
    }
}




//gfg
// {
//         // Your code here
//         stack<int> s2;
//         vector<long long> s1;
//         for(int i=arr.size()-1;i>=0;i--)
//     {
//         while(!s2.size()==0)
//         {
//             if(s2.top()<=arr[i])
//             {
//                 s2.pop();
//             }
//             else
//             {
//                 s1.push_back(s2.top());
//                 break;
//             }
//         }
//         if(s2.size()==0)
//         {
//             s1.push_back(-1);
//         }
//         s2.push(arr[i]);
//     }
//     reverse(s1.begin(),s1.end());
//     return s1;
//     }