class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int c=32-__builtin_clz(n);
      //  cout<<c;
        int ans=(1<<(c+1))-1;
        bool issorted=true;
       // cout<<ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){ans=ans&i;
            issorted=false;}
            //cout<<ans;
        }
        if(issorted)return 0;
        
        return ans;
        
    }
};