class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){ans[i][j]=0;
             
                q.push({i,j});


                }
            }
        }
        while(!q.empty()){
            pair<int, int> p = q.front();
            int a = p.first;
            int b = p.second;
            q.pop();
            vis[a][b]=true;
            if(a+1<n && !vis[a+1][b]){
                ans[a+1][b] = min(ans[a+1][b], ans[a][b]+1);
                q.push({a+1,b});
            }
            if(b+1<m && !vis[a][b+1]){
                ans[a][b+1] = min(ans[a][b+1], ans[a][b]+1);
                q.push({a,b+1});
            }
            if(a-1>=0 && !vis[a-1][b]){
                ans[a-1][b] = min(ans[a-1][b], ans[a][b]+1);
                q.push({a-1,b});
            }
            if(b-1>=0 && !vis[a][b-1]){
                ans[a][b-1] = min(ans[a][b-1], ans[a][b]+1);
                q.push({a,b-1});
            }
            
        }
     return ans;   
    }
};