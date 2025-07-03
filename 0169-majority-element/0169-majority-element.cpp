/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         unordered_map<int,int>frq;
         int maxi=0;
         int ans=0;
         for(int i=0;i<nums.size();i++){
             frq[nums[i]]++;
             if(frq[nums[i]]>maxi){
                 maxi=frq[nums[i]];
                 ans=nums[i];
             }
         }
         return ans;
    }
};
// @lc code=end

