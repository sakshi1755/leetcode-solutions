#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int idx = upper_bound(prefix.begin(), prefix.end(), queries[i]) - prefix.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};
