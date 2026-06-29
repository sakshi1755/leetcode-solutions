class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long high = 1e18;
        long long low = 0;
        long long mini = 0;
        long long n = value.size();
        while (low <= high) {
            long long mid = low + ((high - low) / 2);
            long long count = 0;
            for (int i = 0; i < n; i++) {
                if (value[i] >= mid) {
                    count += ((value[i] - mid) / decay[i] + 1);
                }
            }
            if (count >= m) {
                low = mid + 1;
                mini = max(mini, mid);
            } else {
                high = mid - 1;
            }
        }
        long long ans = 0;
        mini++;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long count = 0;
            if (value[i] >= mini) {
                count += ((value[i] - mini) / decay[i] + 1);
                if (count <= m) {
                    long long temp = 1LL * count * value[i] -
                                     1LL * decay[i] * count * (count - 1) / 2;
                    temp %= mod;
                    ans += temp;
                    ans %= mod;
                    m -= count;
                    value[i]=value[i]-decay[i]*(count);

                } else {
                    long long temp =
                        1LL * m * value[i] - 1LL * decay[i] * m * (m - 1) / 2;
                    temp %= mod;
                    ans += temp;
                    ans %= mod;
                    value[i]=value[i]-decay[i]*(m);
                    m -= m;
                      
                
                }
            }
        }
        
        if(m){
            sort(value.begin(),value.end(),greater<int>());
           for(int i=0;i<min((long long)m,n);i++){
              if(value[i]>0){  ans+=value[i];
                ans%=mod;
              }
            }

        }

        return ans;
    }
};