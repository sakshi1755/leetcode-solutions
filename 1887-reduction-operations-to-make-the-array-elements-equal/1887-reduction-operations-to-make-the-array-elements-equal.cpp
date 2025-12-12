class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>hffm(n,0);
        hffm[0]=0;
        long long ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                hffm[i]=hffm[i-1]+1;
            }
            else{
                hffm[i]=hffm[i-1];
            }
            ans+=hffm[i];

        }
        return ans;
        
    
        
    }
};