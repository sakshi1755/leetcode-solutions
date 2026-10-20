class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>div;
        for(int i=1;i*i<=n;i++){
            if(n%i ==0){div.push_back(i);
            if(n/i!=i)div.push_back(n/i);
            }
        }
        vector<int>sortednums=nums;
        
        sort(sortednums.begin(),sortednums.end());
        if(nums==sortednums){
            long long ans=0;
            for(int i=0;i<div.size();i++){
                ans+=div[i];
            }
            return ans;
        }
        int dn=div.size();
        long long ans=0;
        for(int i=0;i<dn;i++){
            int divisor=div[i];
            int block=divisor;
            int noofblock=n/block;
            int currblock=0;
             bool ok=true;
            while(currblock<noofblock){
                int si=currblock*block;
                int ei=si+block;
                unordered_map<int,int> mp;               
                for(int j=si;j<ei;j++){
                    mp[sortednums[j]]++;

                }
                
                for(int j=si;j<ei;j++){
                    if(!mp[nums[j]]){
                        ok=false;
                        break;
                    }
                    else mp[nums[j]]--;

                }
                if(!ok)break;
                int dip=0;
                int pivot=-1;
                for(int j=si+1;j<ei;j++){
                    if(nums[j]<nums[j-1]){
                        dip++;
                        pivot=j;
                    }

                }
                if(dip>1)ok=false;
                if(dip==1 && nums[ei-1]>nums[si])ok=false;
                if(!ok)break;
                currblock++;
            }
            if(ok)ans+=divisor;
            

        }
        return ans;
        
    }
};