/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int count=0;
        for(int i=0;i<nums.size();i++){ 
            if(nums[i]==1){
                count++;
            }else{
                maxi=max(maxi,count);
                count=0;
            }
        }
        return max(maxi, count); // In case the array ends with 1s
    }
};
// @lc code=end

