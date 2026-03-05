class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,0);
        int mini=prices[0];
        for(int i=1;i<n; i++){
            mini=min(prices[i],mini );
            dp[i]=max(dp[i-1], prices[i]-mini);
        }
        return dp[n-1];
        
    }
};