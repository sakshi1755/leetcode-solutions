class Solution {
public:
    int minOperations(vector<int>& nums) {
        int totalgcd=nums[0];
        int n=nums.size();
        int c1=0;
        for (int i=0;i<n;i++){
            totalgcd=gcd(totalgcd,nums[i]);
            if(nums[i]==1)c1++;
        }
        if(totalgcd!=1)return -1;
        if(c1)return n-c1;
        int minarray=n;
        //int tgr=0;
        for(int i=0;i<n;i++){
            int tg=nums[i];
            
            for(int j=i+1;j<n;j++){
                tg=gcd(nums[j],tg);
                if(tg==1){
                    minarray=min(minarray,j-i+1);
                    
                    break;

                }
            }
            if(minarray==2)break;
        }
        return minarray+n-2;
       // else return minarray+1+(n-minarray);


      


    }
};