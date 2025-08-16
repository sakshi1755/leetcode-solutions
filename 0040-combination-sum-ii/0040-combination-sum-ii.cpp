class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        vector<int>path;
        dfs(candidates,0,target,path,res);
        return res;
        
    }
    void dfs(vector<int>&candidates,int start, int target,vector<int>&path,vector<vector<int>>&res){
        if(target==0)res.push_back(path);
      else if(target>0){
            for(int i=start;i<candidates.size();i++){
                 if(i > start && candidates[i] == candidates[i-1]) continue;
                  path.push_back(candidates[i]); 
            dfs(candidates,i+1,target-candidates[i],path,res);
            path.pop_back();
            }

        }


    }
};