class Solution {
public:
    int rearrangeSticks(int n, int k) {
        long long mod= 1e9 + 7;
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
        for(long long i=0;i<=n;i++){
            for(long long j=0;j<=k;j++){
                if(i==0 && j==0){dp[i][j]=1;
                continue;}
                 if(i==0 || j==0)dp[i][j]=0;
                else{
                    dp[i][j]+=(dp[i-1][j-1])%mod;
                    dp[i][j]+=(((i-1)*(dp[i-1][j])))%mod;
                    dp[i][j]%=mod;

                }
            }
        }
        return dp[n][k]%mod;
    }
};