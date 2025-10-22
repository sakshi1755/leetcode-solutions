class NeighborSum {
public:
    vector<vector<int>>g;
    int n;
    NeighborSum(vector<vector<int>>& grid) {
        g=grid;
        n=grid.size();
    }
    
    int adjacentSum(int value) {
        int valrow=0;
        int valcol=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==value){
                    valrow=i;
                    valcol=j;
                    break;
                }
            }
        }
        int ans=0;
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++){
            if(valrow+dir[i].first>=0 && valcol+dir[i].second<n && valrow+dir[i].first<n &&valcol+dir[i].second>=0){
                ans+=g[valrow+dir[i].first][valcol+dir[i].second];

            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
          int valrow=0;
        int valcol=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==value){
                    valrow=i;
                    valcol=j;
                    break;
                }
            }
        }
        int ans=0;
        vector<pair<int,int>>dir={{1,1},{-1,-1},{-1,1},{1,-1}};
        for(int i=0;i<4;i++){
            if(valrow+dir[i].first>=0 && valcol+dir[i].second<n && valrow+dir[i].first<n &&valcol+dir[i].second>=0){
                ans+=g[valrow+dir[i].first][valcol+dir[i].second];

            }
        }
        return ans;
        
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */