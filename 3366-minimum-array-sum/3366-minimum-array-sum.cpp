class Solution {
public:
    long long solve(int i,int op1,int op2,int k,vector<int>& nums,vector<vector<vector<long long>>>&dp){
        if(i>=nums.size())return 0;
        if(dp[i][op1][op2]!=-1)return dp[i][op1][op2];
        long long ans=nums[i]+solve(i+1,op1,op2,k,nums,dp);
        if(op1>0){
            ans=min(ans,solve(i+1,op1-1,op2,k,nums,dp)+(nums[i]+1)/2);
        }
        if(op2>0 && nums[i]>=k){
            ans=min(ans,solve(i+1,op1,op2-1,k,nums,dp)+nums[i]-k);
            if(op1>0){
                ans=min(ans,solve(i+1,op1-1,op2-1,k,nums,dp)+(nums[i]-k+1)/2);
              if(((nums[i]+1)/2)>=k) ans= min(ans,solve(i+1,op1-1,op2-1,k,nums,dp)+(nums[i]+1)/2-k);
            }
        }
        return dp[i][op1][op2]=ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
       vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(op1+1,vector<long long>(op2+1,-1)));
       return solve(0,op1,op2,k,nums,dp);
    }
};