class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string t;
            for (int i = 1; i < s.size(); i++) {
                int val = (s[i] - '0' + s[i - 1] - '0') % 10;
                t.push_back('0' + val);
            }
            s = t;
        }
        return s[0] == s[1];
    }
};
