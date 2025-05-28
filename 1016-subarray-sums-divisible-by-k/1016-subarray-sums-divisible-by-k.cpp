class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1; // base case
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int rem = sum % k;
            // normalize negative remainder
            if (rem < 0) rem += k;

            count += remainderCount[rem];
            remainderCount[rem]++;
        }

        return count;
    }
};