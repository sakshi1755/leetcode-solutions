/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        int n= nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        int ans=0;
        for (int i = 0; i < n; i++) {

            if(i!=0)prefixSum[i] = prefixSum[i - 1] + nums[i];
           
            if (prefixSum[i] == k) {
                ans++;
            }
            if (map.find(prefixSum[i] - k) != map.end()) {
                ans += map[prefixSum[i] - k];
                
            }
             map[prefixSum[i]] ++;

        }
        return ans;
        
      
    }
};
// @lc code=end

