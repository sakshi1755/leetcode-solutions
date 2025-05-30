class Solution {
  public:
    int solve(vector<int>& arr, int n, int ind,int prev,  vector<vector<int>>&dp){
        if(ind>=n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        if(prev!=-1 && arr[prev]>=arr[ind])return dp[ind][prev+1]=solve(arr,n,ind+1,prev,dp);
        else{
            int take=arr[ind]+solve(arr,n,ind+1,ind,dp);
            int nottake=solve(arr,n,ind+1,prev,dp);
            return dp[ind][prev+1]=max(take,nottake);
        }
        
    }
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(arr,n,0,-1,dp);
        // Your code goes here
    }
};