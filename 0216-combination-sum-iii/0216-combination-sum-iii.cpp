class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates={1,2,3,4,5,6,7,8,9};
        return combinationSum2(candidates,n,k);
    }
     vector<vector<int>> combinationSum2(vector<int>& candidates, int target,int k) {
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        vector<int>path;
        dfs(candidates,0,target,path,res,k);
        return res;
        
    }
    void dfs(vector<int>&candidates,int start, int target,vector<int>&path,vector<vector<int>>&res,int k){
        if(target==0 && k==0)res.push_back(path);
      else if(target>0 && k>0){
            for(int i=start;i<candidates.size();i++){
                 if(i > start && candidates[i] == candidates[i-1]) continue;
                  path.push_back(candidates[i]); 
            dfs(candidates,i+1,target-candidates[i],path,res,k-1);
            path.pop_back();
        
            }

        }


    }
};