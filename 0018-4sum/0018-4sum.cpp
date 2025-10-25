class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long n = nums.size();
        vector<vector<int>> ans;
        for(long long i = 0; i < n; i++) {
            for(long long j = i + 1; j < n; j++) {
                long long t = (long long)target - (long long)nums[i] - (long long)nums[j];
                set<long long> s;
                for(long long k = j + 1; k < n; k++) {
                    if(s.find(nums[k]) != s.end()) {
                        ans.push_back({nums[i], nums[j], nums[k], (int)(t - nums[k])});
                        sort(ans.back().begin(), ans.back().end());
                    } else {
                        s.insert(t - (long long)nums[k]);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end()); 
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
