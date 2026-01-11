class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tempans=4;
                vector<vector<int>>dir={{1,0},{0,-1},{0,1},{-1,0}};
                for(int k=0;k<4;k++){
                    if(grid[i][j]==1 && dir[k][0]+i<m && dir[k][1]+j<n && dir[k][0]+i>=0 && j+dir[k][1]>=0  ) if(grid[i+dir[k][0]][j+dir[k][1]]==1)tempans--;
                }
                if(grid[i][j])ans+=tempans;

            }
            
        }
       return ans;
         
    }
};