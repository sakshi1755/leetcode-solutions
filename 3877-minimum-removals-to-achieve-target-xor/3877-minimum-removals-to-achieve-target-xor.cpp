class Solution {
public:
    int solve(int i,int curr,int n, vector<vector<int>>&dp,vector<int>&nums,int target){
        if(i>=n){
            if(curr!=target)return INT_MAX;
            else return 0;
        }
        if(dp[curr][i]!=-1)return dp[curr][i];
        int take=solve(i+1,curr^nums[i],n,dp,nums,target);
        int nottake=solve(i+1,curr,n,dp,nums,target);
        if(nottake<take){
            return dp[curr][i]=nottake+1;
        }
        else{
            return dp[curr][i]=take;
        }
    }
    int minRemovals(vector<int>& nums, int target) {
        int maxi=0;
        int maximsb=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          if(nums[i]!=0)  maximsb=max(maximsb,31-__builtin_clz(nums[i]));
        }
        maxi=(1<<(maximsb+1))-1;
       
        vector<vector<int>>dp(maxi+1,vector<int>(n+1,-1));
        int ans=solve(0,0,n,dp,nums,target);
        if(ans==INT_MAX)return -1;
        else return ans;
        
        
    }
};