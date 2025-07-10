/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        // initialize the last row
    
           dp[0][0] = triangle[0][0];
           for(int i=1;i<n;i++){
              int m=triangle[i].size();
              for(int j=0;j<m;j++){
                if(j==0) dp[i][0] = dp[i-1][0] + triangle[i][0];
                else if(j==m-1) dp[i][m-1] = dp[i-1][m-2] + triangle[i][m-1];
                else {
                    dp[i][j]=min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
              }
           }
           int minSum = INT_MAX;
           for(int i=0;i<n;i++){
              minSum = min(minSum, dp[n-1][i]);
           }
        return minSum;
      
        
        
        
    }
};
// @lc code=end

