class Solution {
public:
    int solve(vector<int>& arr, int k,int si,vector<int>&dp){
        int n=arr.size();
        
        if(si>=n)return 0;
        if(si==n-1)return arr[n-1];
        if(dp[si]!=-1)return dp[si];
        int sum=0;
        int maxi=0;
        for(int i=0;i<k && si+i<n;i++){
            maxi=max(maxi,arr[si+i]);
            sum=max(sum,maxi*(i+1)+solve(arr,k,si+i+1,dp));

        }
        return dp[si]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,k,0,dp);
        
        
    }
};