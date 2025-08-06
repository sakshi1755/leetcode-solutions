/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        //int m=tasks.size();
        for (char task : tasks) {
            freq[task]++;
        }
        int maxi = 0;
        for(auto& it : freq) {
          maxi=max(  it.second,maxi) ;
        }
        int t=0;
         for(auto& it : freq) {
         if(it.second==maxi)t++  ;
        }

       // int i=0;
         int ans=(n)*(maxi-1)+maxi+t-1;
        return max((int)tasks.size(), ans);
    }
};
// @lc code=end

