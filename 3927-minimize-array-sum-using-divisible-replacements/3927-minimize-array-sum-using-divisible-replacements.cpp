class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long maxi = nums.back();
        long long n = nums.size();
        long long sum=0;
        map<long long, long long> r;
        for (long long i = 0; i < n; i++) {
            if (r.find(nums[i]) != r.end()) {
                nums[i] = r[nums[i]];
               
            } else {
                long long j = nums[i];
                while (j<= maxi) {
                    if (r.find(j) == r.end()) {
                        r[j]=nums[i];
                    }
                    j+=nums[i];
                }

            }
             sum+=nums[i];
        }
        return sum;
    }
};