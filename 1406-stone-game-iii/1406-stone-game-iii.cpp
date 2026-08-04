class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<long long>> dp(n + 3, vector<long long>(2, 0));

        dp[n-1][0] = stoneValue[n-1];
        dp[n-1][1] = -stoneValue[n-1];

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < 2; j++){

                if(j == 0){
                    dp[i][j] = stoneValue[i] + dp[i+1][1];

                    if(i+1 < n)
                        dp[i][j] = max(dp[i][j],
                                       stoneValue[i] + stoneValue[i+1] + dp[i+2][1]);

                    if(i+2 < n)
                        dp[i][j] = max(dp[i][j],
                                       stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] + dp[i+3][1]);
                }
                else{
                    dp[i][j] = -stoneValue[i] + dp[i+1][0];

                    if(i+1 < n)
                        dp[i][j] = min(dp[i][j],
                                       -stoneValue[i] - stoneValue[i+1] + dp[i+2][0]);

                    if(i+2 < n)
                        dp[i][j] = min(dp[i][j],
                                       -stoneValue[i] - stoneValue[i+1] - stoneValue[i+2] + dp[i+3][0]);
                }
            }
        }

        if(dp[0][0] > 0) return "Alice";
        if(dp[0][0] < 0) return "Bob";
        return "Tie";
    }
};