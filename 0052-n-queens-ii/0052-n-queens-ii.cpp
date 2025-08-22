class Solution {
public:
    void dfs(int n,int &count,int row,vector<vector<bool>>&isnotallowed){
        if(row==n)count++;
        else{
            for(int j=0;j<n;j++){
            if(!isnotallowed[row][j]){
                
                vector<pair<int,int>>changed;

                for(int i=row+1;i<n;i++){
                    if(!isnotallowed[i][j]){
                        isnotallowed[i][j]=true;
                        changed.push_back({i,j});

                    }

                }
                int col=j+1;
                for(int i=row+1;i<n && col<n;i++){
                    if(!isnotallowed[i][col]){
                        isnotallowed[i][col]=true;
                        changed.push_back({i,col});

                    }
                    col++;
                }
                col=j-1;
                for(int i=row+1;i<n && col>=0;i++){
                    if(!isnotallowed[i][col]){
                        isnotallowed[i][col]=true;
                        changed.push_back({i,col});

                    }
                    col--;
                }
                dfs(n,count,row+1,isnotallowed);
                for(int i=0;i<changed.size();i++){
                    isnotallowed[changed[i].first][changed[i].second]=false;
                }

            }
        }
        }
    }
    int totalNQueens(int n) {
       vector<vector<bool>> isnotallowed(n, vector<bool>(n, false));

        int count=0;
        int row=0;
        dfs(n,count,row,isnotallowed);
        return count;

    }
};