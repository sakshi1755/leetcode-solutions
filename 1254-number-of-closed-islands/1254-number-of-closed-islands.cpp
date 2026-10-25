class Solution {
public:
    vector<int>parent;
    vector<int> rank;
    int findparent(int i){
        if(parent[i]==i)return i;
        return parent[i]=findparent(parent[i]);
    }
    void unite(int i,int j){
        int pi=findparent(i);
        int pj=findparent(j);
        if(rank[pi]<rank[pj])swap(pi,pj);
        parent[pj]=pi;
        if(rank[pi]==rank[pj])rank[pi]++;
    }
    

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int t=m*n;
        parent.resize(t);
        rank.resize(t,0);
        vector<bool>isnotvalid(t,false);
        for(int i=0;i<t;i++)parent[i]=i;
        vector<int>row={1,-1,0,0};
        vector<int>col={0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)continue;
                else{
                    int code=(i)*m+j;
                    for(int k=0;k<4;k++){
                        int nr=i+row[k];
                        int nc=j+col[k];
                        int ncode=nr*m+nc;
                        if(nr<0 || nc<0 || nr>=n || nc>=m ||  grid[nr][nc]==1)continue;
                        unite(code,ncode);

                    }
                    
                }



            }


        }
        for(int j=0;j<m;j++){
            
            if(grid[0][j]==0){
                int code=j;
                int p=findparent(j);
                isnotvalid[p]=true;
                
            }
            if(grid[n-1][j]==0){
                int code=(n-1)*m+j;
                int p=findparent(code);
                isnotvalid[p]=true;
                
            }
        }
        for(int j=0;j<n;j++){
            
            if(grid[j][0]==0){
                int code=j*m;
                int p=findparent(code);
                isnotvalid[p]=true;
                
            }
            if(grid[j][m-1]==0){
                int code=(j)*m+m-1;
                int p=findparent(code);
                isnotvalid[p]=true;
                
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int c=i*m+j;
                    int pc=findparent(c);
                    if(pc==c && !isnotvalid[pc])ans++;
                }
            }
        }
        return ans;
    }
};