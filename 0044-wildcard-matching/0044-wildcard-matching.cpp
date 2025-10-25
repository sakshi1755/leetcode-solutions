/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include <bits/stdc++.h>  
using namespace std;  

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        
        for (int i = 1; i <= m; i++) {
    if (p[i-1] == '*') dp[i][0] = dp[i-1][0];
    else break;
}

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1] ;
                }
                else if(p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
            }

        }
        return dp[m][n];
        
    }
};
// @lc code=end

