/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(4001, 0));
        for(int i=0;i<n;i++){
            for(int j=-2000;j<=2000;j++){
                if( i==0 && j==nums[i] ){
                    dp[i][j+2000]++;

                }
                  if( i==0 &&  j==-nums[i]){
                    dp[i][j+2000]++;

                }
                else if(i>0){
                   if(j - nums[i] + 2000 >= 0 && j - nums[i] + 2000 <= 4000)
                        dp[i][j+2000] += dp[i-1][j-nums[i]+2000];
                    if(j + nums[i] + 2000 >= 0 && j + nums[i] + 2000 <= 4000)
                        dp[i][j+2000] += dp[i-1][j+nums[i]+2000];
                }

                
        }

    }
     return dp[n-1][target+2000];   
    }
};
// @lc code=end

