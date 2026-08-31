class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>freq;
        int maxi=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            maxi=max(maxi,nums[i]);
    
        }
        vector<bool>isprime(maxi+1,true);
        map<int,vector<int>>pf;
        for(int i=2;i<=maxi;i++){
            if(isprime[i]){
            
                if(freq[i])pf[i].push_back(i);
            
                for(int j=i+i;j<=maxi;j+=i){
                    isprime[j]=false;
                    if(freq[j]){
                        pf[j].push_back(i);
                    }

                }
            }
           
        }
        int dk=0;
        map<int,int>fp;
        int ans=0;
        int l=0;
        int r=0;
        while(r<n){
            int v=nums[r];
            for(int i=0;i<pf[v].size();i++){
                int prime=pf[v][i];
                if(fp[prime]==0)dk++;
                fp[prime]++;
            }
            while(dk>k && l<n){
                int lv=nums[l];
                for(int i=0;i<pf[lv].size();i++){
                    int prime=pf[lv][i];
                    fp[prime]--;
                    if(fp[prime]==0)dk--;
                }
                l++;
                


            }
            ans=max(ans,r-l+1);
            r++;
            
        }
        
        
        //ans=max(ans,r-l+1);
        
        
        
        return ans;      
    }
};