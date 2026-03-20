class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
           if(nums[i]==k) nums[i]=0;
           else if(nums[i]>k)nums[i]=1;
           else nums[i]=-1;
        }
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        map<int,int>f;
        
        long long ans=0;
        bool isk=false;
        for(int i=0;i<n;i++){
           
           if(nums[i]==0)isk=true;
            if(isk){  if(pre[i]==1 || pre[i]==0)ans++;
            int t1=pre[i]-1;
          ans+=f[t1];
            ans+=f[pre[i]];
           
            }
            if(!isk)  f[pre[i]]++;
            
             
        }
        return ans;
        

        
    }
};