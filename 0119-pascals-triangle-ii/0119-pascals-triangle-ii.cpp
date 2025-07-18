class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(rowIndex+1);
         dp[0]={1};
       if(rowIndex>0)  dp[1]={1,1};
        for(int i=2;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j==0)dp[i].push_back(1);
                else if(j==i)dp[i].push_back(1);
                else {
                 dp[i].push_back(dp[i-1][j]+dp[i-1][j-1]);
                }
            }
        }
        return dp[rowIndex];
        
    }
};