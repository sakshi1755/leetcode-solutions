/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        map<char, int> count;
        while(r<n){
            count[s[r]]++;
            while(count['a']>0 && count['b']>0 && count['c']>0){
                ans += n-r;
                count[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end

