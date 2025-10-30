class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3) return ans;

        sort(nums.begin(), nums.end()); // minimal but important change

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            unordered_set<int> s;
            unordered_set<string> seen; // to dedupe triplets on the fly

            for (int j = i + 1; j < n; ++j) {
                int need = -nums[i] - nums[j];
                if (s.count(need)) {
                    vector<int> trip = {nums[i], need, nums[j]};
                    sort(trip.begin(), trip.end()); // normalise order
                    string key = to_string(trip[0]) + "#" + to_string(trip[1]) + "#" + to_string(trip[2]);
                    if (seen.insert(key).second) { // inserted first time
                        ans.push_back(trip);
                    }
                }
                s.insert(nums[j]);
            }
        }
        return ans;
    }
};
