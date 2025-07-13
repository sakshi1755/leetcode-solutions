class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0;
        int jump=0;
        int n=nums.size();
        if(n==1)return 0;
        while(curr<n){
           
            if(curr+nums[curr]>=n-1)return jump+1;
            else{
                int maxi=0;
                int next=curr;
                for(int i=1;i<=nums[curr];i++){
                    if(maxi<=nums[curr+i]+curr+i){ maxi=max(maxi,nums[curr+i]+curr+i);
                               next=curr+i;
                    }
                }
                curr=next;
                jump++;
            }
        }
      return jump;  
    }
};