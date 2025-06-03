class Solution {
public:
int solve(int n, vector<int>& cuts,int i,int j, vector<vector<int>>&dp){
   if(j == i + 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i + 1; k < j; k++){
            int cost = solve(n,cuts, i, k, dp) + solve(n,cuts, k, j, dp);
            mini = min(mini, cost);
        }
        
        return dp[i][j] = ((mini == INT_MAX) ? 0 : mini) + (cuts[j] - cuts[i]);
}
    int minCost(int n, vector<int>& cuts) {
          
               cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m,-1));
    
    return solve(n,cuts,0,m-1,dp);    
    }
};