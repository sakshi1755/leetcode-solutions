/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k=n/3;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        vector<int> result;
        for (auto& [num, count] : freq) {
            if (count > k) {
                result.push_back(num);
            }
        }
        return result;
    }
};
// @lc code=end

