class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long mod = 1e9 + 7;
        int m = r - l + 1;

        vector<vector<long long>> prev(2, vector<long long>(m, 1));
        vector<vector<long long>> cur(2, vector<long long>(m));

        for (int len = 2; len <= n; len++) {

            vector<long long> pref(m, 0);
            vector<long long> suff(m, 0);

            for (int i = 1; i < m; i++) {
                pref[i] = (pref[i - 1] + prev[0][i - 1]) % mod;
            }

            for (int i = m - 2; i >= 0; i--) {
                suff[i] = (suff[i + 1] + prev[1][i + 1]) % mod;
            }

            for (int i = 0; i < m; i++) {
                cur[1][i] = pref[i];
                cur[0][i] = suff[i];
            }

            swap(prev, cur);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += prev[0][i] + prev[1][i];
            ans %= mod;
        }

        return ans;
    }
};