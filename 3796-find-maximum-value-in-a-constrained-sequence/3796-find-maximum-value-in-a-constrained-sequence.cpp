class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions,
                   vector<int>& diff) {
        vector<long long> r(n, LLONG_MAX);
        for (int i = 0; i < restrictions.size(); i++) {
            r[restrictions[i][0]] = restrictions[i][1];
        }
        r[0] = 0;
        for (int i = 1; i < n; i++) {
            r[i] = min(r[i], r[i - 1] + diff[i - 1]);
        }
        long long ans = r[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = min(r[i], r[i + 1] + diff[i]);
            ans = max(ans, r[i]);
        }
        return ans;
    }
};