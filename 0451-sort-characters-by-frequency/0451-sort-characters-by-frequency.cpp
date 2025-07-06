class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;

        for (char c : s) {
            m[c]++;
        }

        vector<pair<int, char>> v;
        for (auto it : m) {
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string result = "";
        for (auto p : v) {
            result += string(p.first, p.second);
        }

        return result;
    }
};
