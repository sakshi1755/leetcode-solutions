/*
 * @lc app=leetcode id=2472 lang=cpp
 *
 * [2472] Maximum Number of Non-overlapping Palindrome Substrings
 */

// @lc code=start
class Solution {
public:
    bool ispali(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n,0);

        for(int i=n-k;i>=0;i--){
          if(i+1<n) dp[i]=dp[i+1];
           for(int j=i+k-1;j<n;j++){
               if(ispali(s,i,j)){
                if(j+1<n)   dp[i]=max(dp[i],1+dp[j+1]);
                else dp[i]=max(dp[i],1);
               }
           }


            
        }
        return dp[0];
    }
};
// @lc code=end

