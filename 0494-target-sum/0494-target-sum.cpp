/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   void solve(int i, int n, vector<int>& nums, int target, int currsum, int &ans){
       if(i==n){
           if(currsum==target){
               ans++;
           }
           return;
       }
       solve(i+1,n,nums,target,currsum+nums[i],ans);
       solve(i+1,n,nums,target,currsum-nums[i],ans);
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int currsum=0;
        int ans=0;
        //int currsum=0;
         solve(0,n,nums,target,currsum,ans);
        return ans;

    }

};
// @lc code=end

