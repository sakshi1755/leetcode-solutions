class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        map<int, int> lastRain; // lake -> last rain day
        set<int> zeros;         // dry days
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeros.insert(i);
            } else {
                int lake = rains[i];
                if (lastRain.count(lake)) {
                    // Find zero day after last rain
                    auto it = zeros.lower_bound(lastRain[lake]);
                    if (it == zeros.end()) return {};
                    ans[*it] = lake;
                    zeros.erase(it);
                }
                lastRain[lake] = i;
                ans[i] = -1;
            }
        }
        for (int i : zeros) ans[i] = 1; // arbitrary
        return ans;
    }
};
