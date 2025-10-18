class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>=n/2)return n;
        else{
            map<int,int>frq;
            for(int i=0;i<n;i++){
                nums[i]-=k;
               
            }
            map<int,int> count;
            sort(nums.begin(),nums.end());
            for(int i=1;i<n;i++){
                if(nums[i]<=nums[i-1]){
                   nums[i] = min(nums[i - 1] + 1, nums[i] + 2*k);

                }


            }
            for(int i=0;i<n;i++){
             frq[nums[i]]++;

            }
            long long ans=0;
            for(auto it: frq){
                if(it.second>1){
                    ans=ans+it.second-1;
                }
            }
            return n-ans;
        }

        
    }
};