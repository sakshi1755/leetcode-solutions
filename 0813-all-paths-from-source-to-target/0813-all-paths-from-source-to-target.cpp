class Solution {
public:
    void dfs(vector<vector<int>>& graphmap,vector<int>&path,int end,vector<vector<int>>&res)
    {
        if(end==0)res.push_back(path);
        else{
            for(int i=0;i<graphmap[end].size();i++){
                path.push_back(graphmap[end][i]);
                dfs(graphmap,path,graphmap[end][i],res);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        int n=graph.size();
        vector<int>path={n-1};
        int end=graph.size()-1;
        vector<vector<int>>graphmap(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                graphmap[graph[i][j]].push_back(i);

            }
        }
        dfs(graphmap,path,end,res);
        for(int i=0;i<res.size();i++){
            reverse(res[i].begin(),res[i].end());
        }
        return res;
        
    }
};