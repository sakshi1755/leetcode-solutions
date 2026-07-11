class Solution {
public:
    long long getSum(vector<int>& nums) {
        vector<long long>tempnums;
        tempnums.push_back(0);
        vector<long long>pref;
        pref.push_back(0);
        pref.push_back(0);
        for(long long i=0;i<nums.size();i++){
            tempnums.push_back(nums[i]);
            tempnums.push_back(0);
            pref.push_back(nums[i]+pref.back());
            pref.push_back(0+pref.back());

        }
        long long n=tempnums.size();
        vector<long long>p(n,0);
        long long c=0;
        long long r=-1;
        for(long long i=0;i<n;i++){
            if(i<r){
                p[i]=min(p[c-(i-c)],r-i);
            }
            while(i+p[i]+1<n && i-p[i]-1>0 &&tempnums[i+p[i]+1]==tempnums[i-p[i]-1]){
                p[i]++;
            }
            if(p[i]+i>r){
                c=i;
                r=p[i]+i;
            }
        }
        long long maxi=0;
        for(long long i=0;i<n;i++){
            maxi=max(maxi,pref[i+p[i]+1]-pref[i-p[i]]);
        }
        return maxi;


    }
};