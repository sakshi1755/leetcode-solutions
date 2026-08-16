class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            int temp = j;
            for (int i = 0; i < n / 2; i++) {
                int a = s[i] - 'a';
                int b = s[n - 1 - i] - 'a';
                temp += min(((a - b + 26) % 26), ((b - a + 26) % 26));
            }
            ans = min(temp, ans);
            char first = s[0];
            s.erase(s.begin());
            s.push_back(first);
        }
        return ans;
    }
};
