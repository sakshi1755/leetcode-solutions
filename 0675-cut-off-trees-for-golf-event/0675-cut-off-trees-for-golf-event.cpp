class Solution {
public:
    int bfs(int sr,int sc, int er,int ec,vector<vector<int>>& forest,int n, int m ){
        if(sr==er && sc==ec)return 0;
        vector<vector<bool>>isvisited(n,vector<bool>(m,false));
        queue<vector<int>>q;
        q.push({sr,sc,0});
        isvisited[sr][sc]=true;
        int row[4]={1,-1,0,0};
        int col[4]={0,0,1,-1};
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int d=q.front()[2];
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m || isvisited[nr][nc] || forest[nr][nc]==0)continue;
                if(nr==er && nc==ec)return d+1;
                isvisited[nr][nc]=true;
                q.push({nr,nc,d+1});
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
          int n=forest.size();
          int m=forest[0].size();
          int ans=0;
          
          vector<vector<int>>trees;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1)trees.push_back({forest[i][j],i,j});
            }
          }
          int tn=trees.size();
          if(tn==0)return 0;
          if(forest[0][0]==0)return -1;
          sort(trees.begin(),trees.end());
          ans+=bfs(0,0,trees[0][1],trees[0][2],forest,n,m);
          if(ans==-1)return -1;
          for(int i=0;i<tn-1;i++){
            int temp=bfs(trees[i][1],trees[i][2],trees[i+1][1],trees[i+1][2],forest,n,m);
            if(temp==-1)return -1;
            ans+=temp;
          }
          return ans;

    }
};