class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return false;

        map<int,bool> isp;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (isp.count(nums[r])) return true;

            isp[nums[r]] = true;

            if (r - l == k) {
                isp.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};
