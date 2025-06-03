// User function Template for C++

class Solution {
  public:
    bool palindrome(string &s,int si, int ei,vector<vector<int>>&pal){
        if(si>ei)return true;
        if(pal[si][ei]!=-1)return pal[si][ei];
       
            if (s[si] != s[ei])
        return pal[si][ei] = 0;

            else return pal[si][ei] = palindrome(s, si + 1, ei - 1, pal);
    }
    int solve(string &s,int si, int ei, int n,  vector<vector<int>>&dp, vector<vector<int>>& pal){
        if(si > ei) return 0;
        if(si>=n-1)return 0;
        if(si==ei)return dp[si][ei]=0;
        if(dp[si][ei]!=-1)return dp[si][ei];
        if(palindrome(s,si,ei,pal))return 0;
        int mini=INT_MAX;
        for(int k=si;k<ei;k++){
            if (palindrome(s, si, k, pal)) {
        int right = solve(s, k + 1, ei, n, dp, pal);
        mini = min(mini, 1 + right);
    }
        }
        return dp[si][ei]=mini;
        
    }
    int palPartition(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
           vector<vector<int>> pal(n , vector<int>(n , -1));
        return solve(s,0,n-1,n,dp,pal);
        
    }
};