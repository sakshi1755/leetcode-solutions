/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int countAtMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        map<int, int> count;

        while (r < n) {
            count[nums[r]]++;
            while (count.size() > k) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
       
    
        

        
        
    }
};
// @lc code=end

