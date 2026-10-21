class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>seen;

        for(int i=0;i<n;i++){
            int need=target-nums[i];
            if(seen.find(need)!=seen.end()){
                return {i,seen[need]};
            }
            seen[nums[i]]=i;
        
            
        }
        return {-1,-1};
        
    }
};