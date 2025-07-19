class Solution {
public:
  int longestPalindromeSubseq(string &s) {

        int n=s.size();
        int start=0;
        string pali="";
        for(int i=n-1;i>=0;i--){
            pali.push_back(s[i]);
            
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0|| j==0) dp[i][j]=0;
                else{
                    if(s[i-1]==pali[j-1])dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }

            }
     
           
        }
           return dp[n][n];
        
    }
    int minInsertions(string s) {
        int n=s.length();
        return n-longestPalindromeSubseq(s);
      
    }
};