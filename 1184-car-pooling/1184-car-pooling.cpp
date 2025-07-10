/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001, 0);
        for (auto& trip : trips) {
            for(int i=trip[1]; i<trip[2]; i++ )
            passengers[i] += trip[0];
           
        }
        for(int i=0; i<1001; i++)
            if(passengers[i] > capacity) return false;
        return true;
    }
};
// @lc code=end

