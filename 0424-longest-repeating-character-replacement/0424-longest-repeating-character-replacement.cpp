class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxf = 0;
        int length = 0;
        int ans = 0;
        unordered_map<char, int> freq;

        while (r < n) {
            freq[s[r]]++;
            maxf = max(maxf, freq[s[r]]);
            
            length++;
            while (l <= r && length - maxf > k) {
                freq[s[l]]--;
                length--;
                l++;
            }

            ans = max(ans, length);
            r++;
        }
        return ans;
    }
};
