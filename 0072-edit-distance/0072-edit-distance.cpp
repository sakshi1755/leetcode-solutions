class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0)dp[i][j]=0;
                else{
                    if(i==0)dp[i][j]=j;//inserion
                   else  if(j==0)dp[i][j]=i;//deletion
                    else{
                    if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                    else{
                        int ins=1+dp[i][j-1];
                        int del=1+dp[i-1][j];
                        int rep=1+dp[i-1][j-1];
                        int temp=min(ins,del);
                        dp[i][j]=min(temp,rep);
                    }
                    }
                }
            }
        }
    return dp[n][m];    
    }
};