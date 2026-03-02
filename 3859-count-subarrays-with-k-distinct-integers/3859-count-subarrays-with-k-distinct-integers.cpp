class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        map<int,int>freq;
        int validnum=0;
        int uni=0;
        int r=0;
        int l=0;
      long long ans=0;
        int extra=0;
        int n=nums.size();
        while(r<n){
            freq[nums[r]]++;
            if(freq[nums[r]]==1)uni++;
            if(freq[nums[r]]==m)validnum++;
            if(uni>k){
               // l++;
                freq[nums[l]]--;
                if(freq[nums[l]]==0)uni--;
                if(freq[nums[l]]==m-1)validnum--;
                extra=0;
                l++;
            }
            if(uni==k && validnum==k){
                while(uni==k && validnum==k){
                   
                    freq[nums[l]]--;
                    if(freq[nums[l]]==0) {
                        uni--;



                    }
                    if(freq[nums[l]]==m-1)validnum--;

                    extra++;
                     l++;
                }
                
                l--;
                freq[nums[l]]++;
                if(freq[nums[l]]==1)uni++;
                extra--;
                validnum++;
                ans+=extra+1;

            }
            r++;
        }
        return ans;


        
    }
};