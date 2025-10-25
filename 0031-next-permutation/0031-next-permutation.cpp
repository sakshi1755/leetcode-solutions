class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool isansfound=false;
        int indx=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
              //  swap(nums[i-1],nums[i]);
                isansfound=true;
                indx=i-1;
                break;
            }


        }
        if(isansfound){
            int mini=INT_MAX;
            int minindx=-1;
        for(int i=indx+1;i<n;i++){
            
            if(nums[i]>nums[indx] && nums[i]<=mini){
                mini=nums[i];
                minindx=i;
            }

        }
        swap(nums[minindx],nums[indx]);
        reverse(nums.begin()+indx+1,nums.end());
            
            
        return ;    
        }
        else {
            sort(nums.begin(),nums.end());
            return ;
        }
    }
};