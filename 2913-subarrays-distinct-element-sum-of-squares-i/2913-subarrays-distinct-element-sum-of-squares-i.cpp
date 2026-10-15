class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long ans=0;
        long long n=nums.size();
        for(int i=0;i<n;i++){
            map<int,int>mp;
            long long d=0;
            for(int j=i;j<n;j++){
                if(!mp[nums[j]])d++;
                mp[nums[j]]++;
                 ans+=(d*d);
            }
           

        }
        return ans;
        
    }
};