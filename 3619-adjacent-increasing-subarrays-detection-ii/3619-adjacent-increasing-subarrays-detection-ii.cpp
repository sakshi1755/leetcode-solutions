class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 1;
        long long l = 0;
        long long r = 1;
        long long newstart = l;
        
        while (l <= r && r < n && l < n) {
            if (nums[r] > nums[r - 1]) {
                r++;
            } else {
                if (newstart == l) {
                    ans = max(ans, (r - newstart) / 2);
                    newstart = r;
                    r++;
                } else {
                    long long temp = min(newstart - l, r - newstart);
                    ans = max(ans, temp);
                    l = newstart;
                }
            }
        }

        // ✅ handle full increasing case
          ans = max(ans, min(newstart - l, r - newstart));
        ans = max(ans, (r - newstart) / 2);  

        return ans;
    }
};
