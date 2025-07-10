/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0]=matrix[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
            if(i==0 ) {
                dp[0][j]=matrix[0][j];

            }
            else if(j==0){
                dp[i][0]=min(dp[i-1][0], dp[i-1][1])+matrix[i][0];
            }
            else if(j==n-1){
                dp[i][n-1]=min(dp[i-1][n-2], dp[i-1][n-1])+matrix[i][n-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]))+matrix[i][j];
            }
           



            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            ans=min(ans, dp[n-1][i]);
        }
        return ans;
        
    }
};
// @lc code=end

