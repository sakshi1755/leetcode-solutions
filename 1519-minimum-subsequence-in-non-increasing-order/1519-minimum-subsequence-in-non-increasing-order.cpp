class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        vector<int>ans;
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];

        }
        for(int i=0;i<n;i++){
            if(prefix[i]>(prefix[n-1]-prefix[i])){
                ans.push_back(nums[i]);
                break;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};