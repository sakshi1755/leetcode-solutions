class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)adj[i].push_back(j);
            }
        }
        vector<int>isv(n,false);
        queue<int>q;
        int count=0;
        for(int i=0;i<n;i++){
        if(!isv[i]){
            count++;
            q.push(i);
            while(!q.empty()){
                int f=q.front();
                q.pop();
                  isv[f]=true;
                int m=adj[f].size();
     
                for(int j=0;j<m;j++){
                    int node=adj[f][j];
                    if(!isv[node]){
                        q.push(node);
                    }
                }
            }
        }

        }
    return count;    
    }
};