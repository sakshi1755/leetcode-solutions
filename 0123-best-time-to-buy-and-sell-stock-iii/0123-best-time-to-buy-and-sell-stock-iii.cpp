#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long getans(int k, vector<int>& prices,int n, int i, int buy, int transactions, vector<vector<vector<long long>>>& dp) {
        if(i==n || transactions==0)return 0;
        if(dp[i][buy][transactions]!=-1)return dp[i][buy][transactions];
        long long profit=0;
        if(buy==0){
            long long bought=-prices[i]+getans(k, prices, n, i+1, 1, transactions, dp);
            long long skipped=getans(k, prices, n, i+1, 0, transactions, dp);
            profit=max(bought, skipped);
            profit=max(0LL, profit);
        }
        else{
            long long sold=prices[i]+getans(k, prices, n, i+1, 0, transactions-1, dp);
            long long skipped=getans(k, prices, n, i+1, 1, transactions, dp);
            profit=max(sold, skipped);
            profit=max(0LL, profit);
        }
        return dp[i][buy][transactions]=profit;
   


    }
    int maxProfit( vector<int>& prices) {
        int n=prices.size();
        int k=2;
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(2,vector<long long>(k+1,-1)));
        int ans=getans(k, prices, n, 0, 0, k, dp);
        return ans;
    }
};