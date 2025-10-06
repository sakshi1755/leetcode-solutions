#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        // Relaxation loop (multiple passes to propagate updates)
        for (int k = 0; k < n * n; k++) { 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], max(grid[i][j], dp[i - 1][j]));
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], max(grid[i][j], dp[i][j - 1]));
                    if (i < n - 1)
                        dp[i][j] = min(dp[i][j], max(grid[i][j], dp[i + 1][j]));
                    if (j < n - 1)
                        dp[i][j] = min(dp[i][j], max(grid[i][j], dp[i][j + 1]));
                }
            }
        }

        return dp[n - 1][n - 1];
    }
};
