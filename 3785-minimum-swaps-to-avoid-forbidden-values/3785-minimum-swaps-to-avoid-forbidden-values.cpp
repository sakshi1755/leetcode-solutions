class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n=forbidden.size();
        map<long long,long long>nf;
        map<long long , long long>ff;
        long long bp=0;
        long long sp=0;
        map<long long, long long>isp;
       // bool isp=true;
        for(int i=0;i<n;i++){
            nf[nums[i]]++;
            ff[forbidden[i]]++;

        }
        for(int i=0;i<n;i++){
            
            if(nums[i]==forbidden[i]){
                bp++;
                isp[nums[i]]++;
            }
            sp=max(sp,isp[nums[i]]);
            if(nf[nums[i]]+ff[nums[i]]>n)return -1;



        }
        return max((bp+1)/2, sp);
        
    }
};