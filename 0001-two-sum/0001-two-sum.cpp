/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
             int com=target-nums[i];
            if (m.find(com) != m.end()) {
             ans={m[com],i};

            }
            m[nums[i]] = i; // Store the index of the current number




        }
        return ans;

        
    }
};
// @lc code=end

