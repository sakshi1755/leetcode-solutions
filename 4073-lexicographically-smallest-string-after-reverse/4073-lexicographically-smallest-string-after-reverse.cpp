class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        int n = s.size();
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.begin(), t.begin() + k);
            if (t < ans) {
                ans = t;
            }
            string p = s;
            reverse(p.end() - k, p.end());
            if (p < ans) {
                ans = p;
            }
        }
        return ans;
    }
};