class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1);
        vector<int>suffix(n+1);
        prefix[0]=0;
    
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        suffix[n]=0;
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
             if(nums[i]==0)
            {
                if(prefix[i]+1==suffix[i+1])ans++;
                if(prefix[i]==suffix[i+1]+1)ans++;
                
                if(prefix[i]==suffix[i+1])ans+=2;
             }
        }
        return ans;
    }
};