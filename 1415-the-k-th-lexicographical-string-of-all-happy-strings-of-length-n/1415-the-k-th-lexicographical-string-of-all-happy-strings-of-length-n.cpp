class Solution {
public:
    void dfs(string &s, vector<string> &ans, int n) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        vector<char> c = {'a', 'b', 'c'};
        for (int i = 0; i < 3; i++) {
            if (s.empty()) {
                s += c[i];
                dfs(s, ans, n);
                            s.pop_back();   
            } else if (!s.empty() && s.back() != c[i]) {
                s += c[i];
                dfs(s, ans, n);
                            s.pop_back();   
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string path="";
        dfs(path, ans, n);
        if (ans.size() < k)
            return "";
        return ans[k - 1];
    }
};