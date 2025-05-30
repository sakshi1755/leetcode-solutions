class Solution {
public:
int solve(vector<int>& nums, vector<vector<int>>&dp,int ind,int prev,int n){
    if(ind==n){
    
    return 0;}
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    if(prev!=-1 && nums[prev]>=nums[ind])return dp[ind][prev+1]=solve(nums,dp,ind+1,prev,n);
    else{
       
        int take=1+solve(nums,dp,ind+1,ind,n);
        int nottake=solve(nums,dp,ind+1,prev,n);
        return dp[ind][prev+1]=max(take,nottake);
       
    }


}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n + 1, -1));
        return solve(nums,dp,0,-1,n);
        
    }
};