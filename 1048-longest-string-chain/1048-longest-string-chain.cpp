class Solution {
public:
    bool checkp(string& word1, string& word2) {
        if ((word1.size() + 1) != word2.size())
            return false;
        int ns = 0;
        int l = 0;
        int r = 0;
        while (l < word1.size() && r < word2.size()) {
            if (word1[l] != word2[r]) {
                if (ns == 0) {
                    r++;
                    ns++;
                } else
                    return false;
            }

            else {
                r++;
                l++;
            }
        }
        return true;
    }
    long long getans(vector<string>& words, int n, int ci, int li,
                     vector<vector<long long>> &dp) {
        if (ci == n || li==n+1)
            return 0;
        if(dp[ci][li]!=-1)return dp[ci][li];
    //        for(int x = 0; x <= n; x++) {
    //     if(dp[ci+1][x] == -1) getans(words, n, ci+1, x, dp);
    // }
        if (li == 0) {
            long long take = getans(words, n, ci + 1, ci + 1, dp) + 1;
            long long skip = getans(words, n, ci + 1, li, dp);
            return dp[ci][li] = max(skip, take);
        } else {
            long long ans = max(0LL, getans(words, n, ci + 1, li, dp));
            string word1 = words[li - 1];
            string word2 = words[ci];
            if (checkp(word1, word2)) {
                ans = max(getans(words, n, ci + 1, ci + 1, dp) + 1, ans);
            }
            return dp[ci][li] = ans;
        }
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){ return a.size() < b.size(); });

        int n = words.size();
        vector<vector<long long>> dp(n+1, vector<long long>(n + 1, -1));
        return getans(words, n, 0, 0, dp);
    }
};