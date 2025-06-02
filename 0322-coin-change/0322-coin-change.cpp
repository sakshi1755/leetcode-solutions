class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return 1e9; // impossible
        }
        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = solve(coins, amount, i - 1, dp);
        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + solve(coins, amount - coins[i], i, dp);
        }

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins, amount, n - 1, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
