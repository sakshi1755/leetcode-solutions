class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>l(n,1);
        vector<int>c(n,1);
        int ml=1;

       // map<int,int>c;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && l[j]+1>l[i]){
                    l[i]=l[j]+1;
                    c[i]=c[j];

                    
                    
                }
                else{
                    if(nums[j]<nums[i] && l[j]+1==l[i]){
                        c[i]=c[i]+c[j];



                    }
                }
            }
            maxi=max(maxi,l[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(l[i]==maxi)ans+=c[i];



        }
        return ans;

    }
};