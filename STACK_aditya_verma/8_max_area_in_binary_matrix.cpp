#include<bits/stdc++.h>
using namespace std;
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        vector<int> h;
        for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[0][j]=='1')
                    h.push_back(1);
                else
                    h.push_back(0);
            } //height of buildings when considering only 0th row
        
        int area=MAH(h);

        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                    h[j]=h[j]+1;
                else
                    h[j]=0;
            }

            area=max(area,MAH(h));
        }
        return area;
    }

     int MAH(vector<int>& heights)
    {
        vector<int> l=NSL(heights);
        vector<int> r=NSR(heights);
        int maxm=0;
        for(int i=0;i<heights.size();i++)
        {
            int a=(r[i]-l[i]-1)*heights[i];
            maxm=max(a,maxm);
        }
        return maxm;
    }//end of MAH

     vector<int> NSL(vector<int> s)
    {
        vector<int>ans;
        stack<pair<int,int>> s2;
    for(int i=0;i<s.size();i++)
    {
        while(s2.size()!=0)
        {
            if(s2.top().second>=s[i])
                s2.pop(); 
            else
            {
                ans.push_back(s2.top().first);
                break;
            }
        }
        if(s2.size()==0)
            ans.push_back(-1);
        s2.push({i,s[i]});
    }
         return ans;
    }//end of NSL


    vector<int> NSR(vector<int> s)
    {       vector<int> ans;
            stack<pair<int,int>> s2;
    for(int i=s.size()-1;i>=0;i--)
    {
        while(s2.size()!=0)
        {
            if(s2.top().second>=s[i])
                s2.pop(); 
            else
            {
                ans.push_back(s2.top().first);
                break;
            }
        }
        if(s2.size()==0)
            ans.push_back(s.size());
        s2.push({i,s[i]});
    }
         reverse(ans.begin(),ans.end());
         return ans;
     }//end of NSR