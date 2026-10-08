class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long maxi=*max_element(nums.begin(),nums.end());
        long long low=1;
        int n=nums.size();
        long long high=maxi;
        long long ans=maxi;
        while(low<=high){
            long long mid=low+((high-low)/2);
            long long o=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid)continue;
                o+=(((nums[i]+mid-1)/mid)-1);
            }
            if(o<=maxOperations){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }


        }
        return ans;
    }
};

