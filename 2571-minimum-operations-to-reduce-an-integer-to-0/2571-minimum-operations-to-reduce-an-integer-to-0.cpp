/*
 * @lc app=leetcode id=2571 lang=cpp
 *
 * [2571] Minimum Operations to Reduce an Integer to 0
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        long long ans=0;
        while(n>0){
            if(n & 1){
                if(n & 2){
                    n++;
                    ans++;
                }
                else{
                    n--;
                    ans++;
                }
            }
            n>>=1;
        }
        return ans;
        
    }
};
// @lc code=end

