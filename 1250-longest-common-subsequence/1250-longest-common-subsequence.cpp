class Solution {
public:
    int solve(string &text1, string &text2,  vector<vector<int>>& dp, int i,int j, int n,int m){
        if(i==0||j==0)
        return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i-1]==text2[j-1]){
            return dp[i][j]=solve(text1,text2,dp,i-1,j-1,n,m)+1;
        }
        else return dp[i][j]=max(
    solve(text1, text2, dp, i - 1, j, n, m),
    solve(text1, text2, dp, i, j - 1, n, m)
           );



    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int> (m+1,-1));
        return solve(text1,text2,dp,n,m,n,m);
        
    }
};