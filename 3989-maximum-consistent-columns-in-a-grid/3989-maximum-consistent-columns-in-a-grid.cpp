class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(j==0){
                    int take=dp[i+1][i+1]+1;
                    int nottake=dp[i+1][0];
                    dp[i][j]=max(take,nottake);


                }
                else{
                    int take=0;
                    bool cantake=true;
                    for(int k=0;k<m;k++){
                        if(abs(grid[k][i]-grid[k][j-1])>limit){
                            cantake=false;
                            break;
                        }
                    }
                   if(cantake) take=1+dp[i+1][i+1];
                    int nottake=dp[i+1][j];
                    dp[i][j]=max(take,nottake);
                }


            }
        }
        return dp[0][0];

        
    }
};