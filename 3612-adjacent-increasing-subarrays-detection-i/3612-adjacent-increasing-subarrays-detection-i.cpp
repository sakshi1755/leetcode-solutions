class Solution {
public:
    bool istrue(vector<int>& nums, int k,int l,int r){
        int n = nums.size();
        int m = k - 1;
        int i = l;

        // first subarray
        while (m--) {
            if (i + 1 >= n || nums[i] >= nums[i + 1]) {
                return false;
            }
            i++;
        }

        m = k - 1;
        i = l + k;  // start of 2nd subarray

        // second subarray
        while (m--) {
            if (i + 1 > r || nums[i] >= nums[i + 1]) {
                return false;
            }
            i++;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 2*k - 1;

        while (r < n) {
            if (istrue(nums, k, l, r)) return true;
            l++;
            r++;
        }
        return false;
    }
};
