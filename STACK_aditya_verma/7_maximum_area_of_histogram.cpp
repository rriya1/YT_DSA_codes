#include<bits/stdc++.h>
using namespace std;



    vector<int> NSL(vector<int> s)
    {
        vector<int>ans;
        stack<pair<int,int>> s2;
    for(int i=0;i<s.size();i++)
    {
        while(s2.size()!=0)
        {
            if(s2.top().second>=s[i])
            {
                s2.pop(); 
            }
            else
            {
                ans.push_back(s2.top().first);
                break;
            }
        }
        if(s2.size()==0)
        {
            ans.push_back(-1);
        }
        s2.push({i,s[i]});
    }
 
         return ans;
    }

    vector<int> NSR(vector<int> s)
    {       vector<int> ans;
            stack<pair<int,int>> s2;
    for(int i=s.size()-1;i>=0;i--)
    {
        while(s2.size()!=0)
        {
            if(s2.top().second>=s[i])
            {
                s2.pop(); 
            }
            else
            {
                ans.push_back(s2.top().first);
                break;
            }
        }
        if(s2.size()==0)
        { 
            ans.push_back(s.size());
        }
        s2.push({i,s[i]});
    }

         reverse(ans.begin(),ans.end());
         return ans;
     }

     int largestRectangleArea(vector<int>& heights)
    {
        //map<int,pair<int,int>>;
        vector<int> l=NSL(heights);
        vector<int> r=NSR(heights);
        int maxm=-1;
        for(int i=0;i<heights.size();i++)
        {
            int a=(r[i]-l[i]-1)*heights[i];
            maxm=max(a,maxm);
            //area.push_back(a);
        }
        return maxm;
    }

int main()
{
    int n;
    cout<<"Enter the number of buildings";
    cin>>n;
    vector<int> buildings;
    cout<<endl;
    cout<<"Enter the heights of the buildings: "<<endl;
    for(int i=0;i<n;i++ )
    {
        int h;
        cin>>h;
        buildings.push_back(h);
    }

    int area=largestRectangleArea(buildings);
    cout<<"The largest area is: "<<area;
    return 0;
}