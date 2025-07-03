/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            if (i + 1 >= nums.size() || nums[i] != nums[i + 1]) {
                ans= nums[i];
                break;
            }
        }
     return  ans; 
    }
};
// @lc code=end

