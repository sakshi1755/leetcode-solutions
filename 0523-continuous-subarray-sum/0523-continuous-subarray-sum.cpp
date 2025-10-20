class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0] % k;

        for (int i = 1; i < n; i++) {
            prefix[i] = (prefix[i - 1] + nums[i]) % k;
        }

        set<int> s;
        for (int i = 1; i < n; i++) {
            if(prefix[i]==0)return true;
            if (s.find(prefix[i]) != s.end()) return true;
            s.insert(prefix[i - 1]); // insert previous prefix only
        }
        return false;
    }
};
