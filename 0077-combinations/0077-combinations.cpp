class Solution {
public:
    void dfs(int n,int k,int start,vector<vector<int>>&res,vector<int>&path){
        if(path.size()==k)res.push_back(path);
        else{
            for(int i=start;i<=n;i++){
                path.push_back(i);
                dfs(n,k,i+1,res,path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>path;
        int start=1;
        dfs(n,k,start,res,path);
        return res;
        
    }
};