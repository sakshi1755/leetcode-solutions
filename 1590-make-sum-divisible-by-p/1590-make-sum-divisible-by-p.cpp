class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //3,4,8,10
        //3,4,2,4
        //10-(p[j]-p[i-1]) should be divisible by 6
        //4-(p[j]%6 -p[i-1]%6)==0
        //p[i-1]=4-p[j]
        ///if p[i-1]==0 then 
        int n=nums.size();
        map<int,int>ind;
        vector<int>prefix(n,0);
        prefix[0]=nums[0]%p;
       //// ind[prefix[0]]=0;
        long long sum=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum%p;
           // ind[prefix[i]]=i;
        }
        sum=sum%p;
        if(sum==0)return 0;
        set<int>s;
        int ans=n;
        ind[0] = -1;
        s.insert(0);
        for(int i=0;i<n;i++){
           
            int findnum=(-sum+prefix[i]+p)%p;
            if(s.count(findnum)){
                int size=i-ind[findnum];
                ans=min(ans,size);
            }
           
            ind[prefix[i]]=i;
            s.insert(prefix[i]);
        }
        return ans == n ? -1 : ans;

        //dry run for 2.....6,9,14,16...//6,0,5,7
        
    }
};