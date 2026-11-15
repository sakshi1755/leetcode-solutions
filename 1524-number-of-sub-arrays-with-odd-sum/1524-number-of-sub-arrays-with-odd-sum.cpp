class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int mod=1e9+7;
        int even=1;
        int odd=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                ans+=odd;
                ans%=mod;
                even++;
                even%=mod;

            }
            else{
                ans+=even;
                even%=mod;
                odd++;
                odd%=mod;

            }
        }
        return ans;

        
    }
};