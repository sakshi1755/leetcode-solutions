class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;  // sum of elements in the current window
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // Total needed to make all elements in window equal to nums[right]
            // If total needed > k, shrink window
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
