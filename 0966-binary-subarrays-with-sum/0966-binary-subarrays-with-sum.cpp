/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int r=0;
        int l=0;
        int sum=0;
        int ans=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;;
            }
            int templ = l;
              while (templ <= r && sum == goal) {
                  ans++;
                    if (nums[templ] != 0) break;
                           templ++;
                                  }

            r++;
        }
        return ans;
    }
};
// @lc code=end

