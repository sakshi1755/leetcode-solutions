class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int &ans,vector<vector<vector<int>>>&visited,int currsum,int m,int n){
        if(i==m-1 && j==n-1){
            visited[i][j][currsum]=true;
            int tempans=currsum^grid[i][j];
            ans=min(ans,tempans);
            return;
        }
        else{
            visited[i][j][currsum]=true;
            currsum^=grid[i][j];
        
            if(i+1<m && !visited[i+1][j][currsum])dfs(i+1,j,grid,ans,visited,currsum,m,n);
            if(j+1<n && !visited[i][j+1][currsum])dfs(i,j+1,grid,ans,visited,currsum,m,n);
            return;

        }
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>visited(m,vector<vector<int>>(n,vector<int>(1023+1,false)));
        int ans=INT_MAX;
        dfs(0,0,grid,ans,visited,0,m,n);
        return ans;
    }
};

