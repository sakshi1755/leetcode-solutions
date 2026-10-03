class Solution {
public:
    long long solve(int s, int e,vector<vector<int>>&dp ){
        if(s>e)return 1;

        if(s==e)return dp[s][e]=1;
        if(dp[s][e]!=-1)return dp[s][e];
        long long ans=0;
        for(int i=s;i<=e;i++){
            ans+=(solve(s,i-1,dp)*solve(i+1,e,dp));
        }
        return dp[s][e]=ans;

    }
    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        solve(0,n-1,dp);
        return dp[0][n-1];
        
    }
};