class Solution {
public:
    long long pow1(long long x, long long n) {
        long long mod=1000000007;
        if(n==0)return 1;
        if(n==1)return x;
        long long temp=pow1(x,n/2);
        long long ans=(temp*temp)%mod;
        if(n%2==1){
            ans=(ans*x)%mod;



        }
        return ans%mod;
      
    }
    int countGoodNumbers(long long n) {
        long long mod=1000000007;
        long long ans=0;
        if(n%2==0){
            long long temp1=(pow1(5,(n/2)))%mod;
            long long temp2=(pow1(4,(n/2)))%mod;
            ans=(temp1*temp2)%mod;
        }
        else{
            long long temp1=(pow1(5,(n/2)+1))%mod;
            long long temp2=(pow1(4,(n/2)))%mod;
            ans=(temp1*temp2)%mod;

        }
        return ans;

        
    }
};