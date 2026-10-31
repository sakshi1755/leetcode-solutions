class Solution {
public:
  int mod=1e9+7;
    int solve(int i,int j, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int n,int m,int dir){
        if(i>=m || j>=n)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j][dir]!=-1)return dp[i][j][dir];
        if(grid[i][j]){
            if(dir==0){
                return dp[i][j][dir]=solve(i,j+1,grid,dp,n,m,1)%mod;
            }
            else{
                return dp[i][j][dir]=solve(i+1,j,grid,dp,n,m,0)%mod;
            }

        }
        long long ans=solve(i,j+1,grid,dp,n,m,1)%mod;
        ans+=(solve(i+1,j,grid,dp,n,m,0)%mod);
        return dp[i][j][dir]=ans%mod;
        
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
      
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(0,0,grid,dp,n,m,0);


    }
};