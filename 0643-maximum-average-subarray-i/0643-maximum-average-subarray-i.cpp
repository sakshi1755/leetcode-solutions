class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int avgs=0;
        for(int i=0;i<k;i++){
            avgs+=nums[i];
        }
        int l=0;
        int r=k-1;
        l++;
        r++;
        double maxi=double(avgs)/k;
        while(r<n){
            avgs=avgs-nums[l-1]+nums[r];
            maxi=max(maxi,double(avgs)/k);
            l++;
            r++;

            

        }
        return maxi;
        
    }
};