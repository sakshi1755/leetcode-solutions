/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isvisited(n, false);
        queue<int> q;
        q.push(0);
        isvisited[0] = true;
         if(0 == n-1)return true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 1; i <= nums[cur] && cur + i < n; ++i) {
                if (!isvisited[cur + i]) {
                    if(cur+i == n-1)return true;  // If the last position is reached, return true.
                    isvisited[cur + i] = true;
                    q.push(cur + i);
                }
            }
        }
        return false;  // If no path is found to reach the last position, return false.
        
    }
};
// @lc code=end

