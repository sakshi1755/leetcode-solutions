class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true);
        int count=0;
        isprime[0]=isprime[1]=false;
        for(int i=2;i<=n;i++){
            for(int j=2; j*i<=n; j++){
                isprime[j*i]=false;
            }
        }
        for(int i=2; i<n;i++){
            if(isprime[i]!=0) count++;
        }
    return count;
    }
};