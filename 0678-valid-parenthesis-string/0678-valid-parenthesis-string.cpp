class Solution {
private:
public:
    bool checkValidString(string s) 
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));

    // Initialize the first row where openingBracket is 0
    for (int ind = 0; ind <= s.size(); ind++) {
        if (s[ind] != ')') {
            dp[ind][0] = 1;
        }
    }

           for(int ind=s.size()-1; ind>=0; ind--){
            for(int openingBracket=0; openingBracket<s.size(); openingBracket++){
                bool ans=false;
                if(s[ind]=='*'){
                    ans|=dp[ind+1][openingBracket+1];
                    if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    ans|=dp[ind+1][openingBracket];
                }else{
                    if(s[ind]=='('){
                        ans|=dp[ind+1][openingBracket+1];
                    }else{
                        if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    }
                }

                dp[ind][openingBracket]=ans;
            }
        }

        return dp[0][0];

    }
};