/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
       int l=0;
       int r=0;
       int oc=0;
       int ans=0;
       while(r<n){
              if(nums[r]%2==1){
                oc++;
              }
              while(oc>k){
                if(nums[l]%2==1){
                     oc--;
                }
                l++;
              }
              if(oc==k){
                int temp = l;
                while(oc==k && temp<=r){
                    ans++;
                    if(nums[temp]%2==1){
                        break;
                    }
                    temp++;
                    

                }
              }
              r++;

       }
       return ans;
    }
};
// @lc code=end

