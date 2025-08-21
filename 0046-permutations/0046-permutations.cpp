class Solution {
public:
    void dfs(vector<int>& nums,map<int,bool> &isvisited, vector<vector<int>>&res, vector<int>&path){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!isvisited[nums[i]]){
                path.push_back(nums[i]);
                isvisited[nums[i]]=true;
                dfs(nums,isvisited,res,path);
                path.pop_back();
                isvisited[nums[i]]=false;


            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        map<int,bool> isvisited;
        vector<vector<int>>res;
        vector<int>path;
        dfs(nums,isvisited,res,path);
        return res;
    }
};