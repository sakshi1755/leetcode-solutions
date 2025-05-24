class Solution {
  public:
    string reverseWords(string &s) {
        string temp = "";
        vector<string> revans;
        string ans;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    revans.push_back(temp);
                    temp = "";
                }
            } else {
                temp.push_back(s[i]);
            }
        }

        // Push the last word if any
        if (!temp.empty()) {
            revans.push_back(temp);
        }

        // Build the final answer string
        for (int i = revans.size() - 1; i >= 0; i--) {
            ans += revans[i];
            if (i != 0) ans += " ";
        }

        return ans;
    }
};
