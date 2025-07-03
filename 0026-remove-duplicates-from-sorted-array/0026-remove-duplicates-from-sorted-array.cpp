/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i =0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int j=0;
        int size=0;
        for(auto i:s){
            nums[j] = i;
            j++;    
            size++;
        }
        return size;
    }
};
// @lc code=end

