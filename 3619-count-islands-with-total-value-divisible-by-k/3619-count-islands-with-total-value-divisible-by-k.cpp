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
    int countIslands(vector<vector<int>>& grid, int k) {
         int n=grid.size();
        int m=grid[0].size();
        int t=m*n;
        parent.resize(t);
        rank.resize(t,0);
        vector<long long>sum(t,0);
        for(int i=0;i<t;i++)parent[i]=i;
        vector<int>row={1,-1,0,0};
        vector<int>col={0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                else{
                    int code=(i)*m+j;
                    for(int k=0;k<4;k++){
                        int nr=i+row[k];
                        int nc=j+col[k];
                        int ncode=nr*m+nc;
                        if(nr<0 || nc<0 || nr>=n || nc>=m ||  grid[nr][nc]==0)continue;
                        unite(code,ncode);

                    }
                    
                }



            }


        }
        int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  int code=(i)*m+j;
                  if(grid[i][j]!=0){
                    int p=findparent(code);
                    sum[p]+=(long long)grid[i][j];
                  }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                int code=(i)*m+j;
                int p=findparent(code);
                if(p==code && sum[p]%k==0)ans++;
            }
        }
        return ans;

        
    }
};