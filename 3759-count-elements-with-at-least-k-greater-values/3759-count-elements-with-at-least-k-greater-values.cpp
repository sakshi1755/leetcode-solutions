class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
        map<int,int>f;
        for(int i=0;i<n-1;i++){
            f[nums[i]]++;
            if(nums[i]!=nums[i+1]){
                if((n-i-1)>=k)ans+=f[nums[i]];
            }

        }
        f[nums[n-1]]++;
        if(n-1-(n-1)>=k)ans+=f[nums[n-1]];
        return ans;
        
    }
};