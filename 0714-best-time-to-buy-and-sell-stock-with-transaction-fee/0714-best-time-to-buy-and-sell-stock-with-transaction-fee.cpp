class Solution {
public:
    long long getans(vector<int>& prices, int fee,int n,int ind, int buy, vector<vector<long long>>&dp){
        if(ind==n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        long long skip=getans(prices,fee,n,ind+1,buy,dp);
        long long profit=max(0LL,skip);
        if(buy==0){
            profit=max(profit,getans(prices,fee,n,ind+1,1,dp)-prices[ind]);
        }
        else{
            profit=max(profit,getans(prices,fee,n,ind+1,0,dp)+prices[ind]-fee);
        }
        return dp[ind][buy]=profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        int ans=getans(prices,fee,n,0,0,dp);
        return ans;
    }
};