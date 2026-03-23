class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        if(n>999){
            ans+=(min((long long)(999999),n)-999);
        }
        if(n>999999){
            ans+=((min((long long)1e9-1,n)-1e6+1)*2);

        }
        if(n>(1e9-1)){
            ans+=((min((long long)1e12-1,n)-1e9+1)*3);
        }
        if(n>(1e12-1)){
            ans+=((min((long long)1e15-1,n)-1e12+1)*4);
        }
        if(n==1e15)ans+=5;
        return ans;
    }
};
// 1,000
// 10,000
// 100,000
// 999,999
// 999,999,999
// 999,999,999,999
// 1,000,000,000,000,000