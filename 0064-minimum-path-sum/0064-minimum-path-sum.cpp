class Solution {
public:
int solve(vector<vector<int>>& grid, int i,int j, int n,int m,vector<vector<int>>&dp  ){
    if(i==0 && j==0)return dp[i][j]=grid[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    if(i>0 && j>0  ){
        int up=solve(grid,i-1,j,n,m,dp);
       // int down=solve(grid,i+1,j,n,m,dp);
        int left=solve(grid,i,j-1,n,m,dp);
       // int right=solve(grid,i,j+1,n,m,dp);
      
        return dp[i][j]=min(up,left)+grid[i][j];
    }
    
    else if(i==0)return dp[i][j]=solve(grid,i,j-1,n,m,dp)+grid[i][j];
        else return dp[i][j]=solve(grid,i-1,j,n,m,dp)+grid[i][j];
    
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,n,m,dp);
        
    }
};