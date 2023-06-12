#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
    {
        vector<int> l=FGL(height);
        vector<int> r=FGR(height);
        int water=0;

        for(int i=0;i<height.size();i++)
        {
            if(l[i]!=-1 && r[i]!=-1 )
                {
                    int area=(min(l[i],r[i])-height[i]);
                    water=water+area;
                }
        }
        return water;
    }

    vector<int> FGL(vector<int> h)
    {
        vector<int> ans;
        int maxi=-1;
        for(int i=0;i<h.size();i++ )
        {
            if(i==0)
            {
                ans.push_back(-1);
                if(maxi<h[i])
                    maxi=h[i];
            }
            else
            {
                if(maxi<h[i])
                {
                    ans.push_back(-1);
                    maxi=h[i];
                }
                else
                    ans.push_back(maxi);
            }
        }
        return ans;
    }

    vector<int> FGR(vector<int> h)
    {
        vector<int> ans;
        int maxi=-1;
        for(int i=h.size()-1;i>=0;i--)
        {
            if(i==h.size())
            {
                ans.push_back(-1);
                if(maxi<h[i])
                    maxi=h[i];
            }
            else
            {
                if(maxi<h[i])
                {
                    ans.push_back(-1);
                    maxi=h[i];
                }
                else
                    ans.push_back(maxi);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }