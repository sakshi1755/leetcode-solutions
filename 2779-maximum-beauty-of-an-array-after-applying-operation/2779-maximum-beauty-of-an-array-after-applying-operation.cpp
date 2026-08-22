class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       map<int,int>tn;
       int maxe=*max_element(nums.begin(),nums.end());
        int mine=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            tn[nums[i]-k]++;
            if(nums[i]-k<mine)tn[mine]++;
            tn[nums[i]+k+1]--;
        }
        long long ans=0;
        long long uptilnow=0;
        for(int i=mine;i<=maxe;i++){
            uptilnow+=tn[i];
            ans=max(uptilnow,ans);
        }
        return ans;
    }
};