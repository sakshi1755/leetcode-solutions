class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int>nums2=nums;
        sort(nums.begin(),nums.end());
        map<int,int>m;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                m[nums[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=m[nums2[i]];
        }
        return ans;
    }
};