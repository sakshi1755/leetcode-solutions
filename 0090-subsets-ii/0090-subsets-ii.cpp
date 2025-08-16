class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        dfs(nums,subset,ans,0);
        return ans;

    }
    void dfs(vector<int>&nums, vector<int>&subset, vector<vector<int>>&ans,int start){
        ans.push_back(subset);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])continue;
            subset.push_back(nums[i]);
            dfs(nums,subset,ans,i+1);
            subset.pop_back();

        }
    }
};