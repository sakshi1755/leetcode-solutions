class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n>0){
            ans=ans*10+n%10;
            n=n/10;

        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,int>ind;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int find=rev(nums[i]);
           // cout<<find<<" ";
            if(ind.count(find)){
                ans=min(ans,abs(ind[find]-i));
            }
            ind[nums[i]]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;


        
    }
};