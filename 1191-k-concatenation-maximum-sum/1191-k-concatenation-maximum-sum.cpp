class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long mod = 1e9 + 7;

        long long l=0;
        long long e=0;
        long long r=0;
        long long sum=0;
        long long ts=0;
        long long ans=0;
        long long n=arr.size();

        while(r<n){
            sum+=arr[r];
            if(sum<0){
                sum=0;
                l=r;
            }
            if(sum>ans){
                ans=sum;
                e=r;
            }
            ts+=arr[r];
            r++;
        }

        ans = max(ans, ts * 1LL * k);

        long long startingsebest=0;
        sum=0;
        for(long long i=0;i<n;i++){
            sum+=arr[i];
            startingsebest=max(startingsebest,sum);
        }

        long long endsebest=0;
        sum=0;
        for(long long i=n-1;i>=0;i--){
            sum+=arr[i];
            endsebest=max(endsebest,sum);
        }

        if(k>1){
           ans = max(ans, ts * 1LL * (k - 2) + startingsebest + endsebest);

        }

        if(k>1){
            for(long long i=0;i<n;i++){
                arr.push_back(arr[i]);
            }

            long long tempans=0;
            r=0;
            sum=0;
            while(r<2*n){
                sum+=arr[r];
                if(sum<0){
                    sum=0;
                }
                if(sum>tempans){
                    tempans=sum;
                }
                r++;
            }
            ans = max(ans, tempans );
        }

        return ans % mod;
    }
};
