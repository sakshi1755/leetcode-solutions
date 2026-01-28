class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>isprime(maxi+1,true);
        isprime[1]=false;
        isprime[0]=false;
        for(int i=2;i<=maxi;i++){
            if(isprime[i]){
                for(int j=i*2;j<=maxi;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int minin=INT_MAX;
        int maxin=INT_MIN;
        for(int i=0;i<n;i++){
            if(isprime[nums[i]]){
                minin=min(i,minin);
                maxin=i;
            }
        }
        return maxin-minin;
        
    }
};