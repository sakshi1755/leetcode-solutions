class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int l=0;
        int r=0;
        int size=0;
        int zeroes=0;
       while(r<n && l<n){
    if(zeroes < k || (zeroes == k && nums[r] == 1)){  // \U0001f527 CHANGED LINE
        size++;
        ans = max(ans, size);
        if(nums[r] == 0) zeroes++;
        r++;
    }
    else {
        if(nums[l] == 0) zeroes--;
        size--;
        l++;
    }
}

        return ans;
    }
};