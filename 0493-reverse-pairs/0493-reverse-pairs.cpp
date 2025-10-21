class Solution {
public:
    void merge(vector<int>& nums, int &ans, int l,int mid,int r){
        int leftside=l;
        int rightside=mid+1;
        while(rightside<=r && leftside<=mid){
            if(((long long)nums[leftside] <= 2LL * nums[rightside])
)leftside++;
            else{
                ans+=mid-leftside+1;
                rightside++;
            }
        }
        vector<int>temp(r-l+1);
        int i=0;
        leftside=l;
        rightside=mid+1;
        while(i<r-l+1){
            if(leftside>mid){
                temp[i]=nums[rightside];
                rightside++;
                i++;
            }
            else if(rightside>r){
                temp[i]=nums[leftside];
                leftside++;
                i++;
            }
            else{
                if(nums[leftside]<nums[rightside]){
                    temp[i]=nums[leftside];
                    leftside++;
                    i++;
                }
                else{
                    temp[i]=nums[rightside];
                    rightside++;
                    i++;
                }
            }
        }
        for(int i=l;i<=r;i++){
            nums[i]=temp[i-(l)];
        }
        

    }
    void mergesort(vector<int>& nums, int &ans, int l,int r){
        if(l>=r)return;
        int mid = l + (r - l) / 2;

        mergesort(nums,ans,l,mid);
        mergesort(nums,ans,mid+1,r);
        merge(nums,ans,l,mid,r);

    }

    int reversePairs(vector<int>& nums) {
      int n=nums.size();
      int ans=0;
      
      mergesort(nums,ans,0,n-1);
      return ans;
    }
};