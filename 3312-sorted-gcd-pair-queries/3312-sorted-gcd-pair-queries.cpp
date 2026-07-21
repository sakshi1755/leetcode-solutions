class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long maxi=*max_element(nums.begin(),nums.end());
        long long n=nums.size();
        vector<long long>gcd(maxi+1,0);
        map<long long,long long>freq;

        for(long long i=0;i<n;i++){
            freq[nums[i]]++;
            
        }
        for(long long i=maxi;i>=1;i--){
            long long count=0;
            for(long long j=i;j<=maxi;j=j+i){
                count+=freq[j];
            }
            gcd[i]=(count*(count-1))/2;
            for(long long j=i*2;j<=maxi;j+=i){
                gcd[i]-=gcd[j];
            }

        }
        vector<long long>totalsum(maxi+1,0);
        long long ts=0;
        
        for(long long i=0;i<=maxi;i++){
            ts+=gcd[i];
            totalsum[i]=ts;
        }
        vector<int>ans;
        for(long long i=0;i<queries.size();i++){
            ans.push_back(lower_bound(totalsum.begin(),totalsum.end(),queries[i]+1)-totalsum.begin());



        }
        return ans;



        
    }
};