//copied rn, understand this
#include<bits/stdc++.h>
using namespace std;

string lcs(string,string, int, int);
//int static t[101][101];//according to the constarint provided

int main()
{
    string x,y;
    //memset(t,-1,sizeof(t));//initialization of the table,can only be done in main if using memset
    cout<<"Enter the string"<<endl;
    cout<<"FIRST: ";
    cin>>x;
    cout<<"SECOND:";
    cin>>y;
    int n=x.size();
    int m=y.size();
    cout<<"size: "<<n<<" "<<m<<endl;
    string s=lcs(x,y,n,m);
    cout<<"The longest common substring size is: "<<s;
    return 0;
}


string lcs(string str1, string str2, int m , int n) {
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(i==0 || j==0)
                    dp[i][j] = 0;
        
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        int i=m,j=n;
        string s;
        while(i>0 && j>0) {
            if(str1[i-1] == str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
            } else {
                if(dp[i][j-1] > dp[i-1][j]) {
                    s.push_back(str2[j-1]);
                    j--;
                } else {
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i > 0) {
            s.push_back(str1[i-1]);
            i--;
        }
        
        while(j > 0) {
            s.push_back(str2[j-1]);
            j--;
        } 
        
        reverse(s.begin(), s.end());
        return s;
    }

