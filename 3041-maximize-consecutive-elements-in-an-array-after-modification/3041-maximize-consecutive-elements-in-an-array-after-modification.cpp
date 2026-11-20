class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n-1][1]=1;
        dp[n-1][0]=1;
        for(int i=n-2;i>=0;i--){
            //when i=0;
            dp[i][0]=1;
            dp[i][1]=1;
            if(nums[i]==nums[i+1]){
                dp[i][0]=dp[i+1][0];
                dp[i][1]=dp[i+1][1];
            }
            if(nums[i+1]==nums[i]+1){
                dp[i][0]=max(dp[i+1][0]+1,dp[i][0]);
            }
            if(nums[i+1]+1==nums[i]+1){
                dp[i][0]=max(dp[i+1][1]+1,dp[i][0]);
            }
            //when j=1;
            if(nums[i]+1+1==nums[i+1]){
                dp[i][1]=max(dp[i+1][0]+1,dp[i][1]);
                

            }
            if(nums[i+1]+1==nums[i]+1+1){
                dp[i][1]=max(dp[i+1][1]+1,dp[i][1]);
            }   

            ans=max(ans,dp[i][0]);
            ans=max(ans,dp[i][1]);         
        }
        return ans;
        
    }
};
//1 2 2 2 4 5 
