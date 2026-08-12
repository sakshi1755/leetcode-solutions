class Solution {
public:
    int solve(int idx, int prev, int tight, string& s,
              vector<vector<vector<int>>>& dp) {
        if (idx >= s.size())
            return 1;
        if (dp[idx][prev][tight] != -1)
            return dp[idx][prev][tight];
        int limitindex = s[idx]-'0';
        int tn;
        if (tight) {
            if (prev == 1) {
                tn = limitindex ^ 1;
                return dp[idx][prev][tight] = solve(idx + 1, 0, tn, s, dp);
            } else {
                int ans = 0;
                for (int i = 0; i <= limitindex; i++) {
                    if (i == limitindex)
                        tn = 1;
                    else
                        tn = 0;
                    ans += solve(idx + 1, i, tn, s, dp);
                }
                return dp[idx][prev][tight] = ans;
            }

        } else {
            if (prev == 1) {
                tn = 0;
                return dp[idx][1][0] = solve(idx + 1, 0, tn, s, dp);
            } else {
                int ans = 0;
                for (int i = 0; i <=1; i++) {
                    tn=0;
                    ans += solve(idx + 1, i, tn, s, dp);
                }
                return dp[idx][prev][tight] = ans;
            }
        }
    }
    int findIntegers(int n) {

        string s = bitset<64>(n).to_string();
        s.erase(0, s.find('1'));

        if (s.empty())
            return 1;
        int st = s.size();
        vector<vector<vector<int>>> dp(
            st + 1, vector<vector<int>>(2, vector<int>(2, -1)));
        // pos,prev,tight
        return solve(0, 0, 1, s, dp);
    }
};