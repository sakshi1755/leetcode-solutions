/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> prefix(n ,0);
        prefix[0]=cardPoints[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + cardPoints[i];
        }
        vector<int> suffix(n ,0);
        suffix[n-1]=cardPoints[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] + cardPoints[i];
        }
        int ans = 0;
        int temp=0;
         int left=0;
         int right=0;
        while(temp<=k){
          if(temp!=0)   left = prefix[temp-1];
          else  left=0;
           if(temp!=k)   right = suffix[n-k+temp];
           else  right=0;
            ans = max(ans, left + right);
            temp++;

        }
        return ans;
    }
};
// @lc code=end

