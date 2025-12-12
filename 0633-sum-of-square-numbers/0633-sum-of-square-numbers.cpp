class Solution {
public:
    bool judgeSquareSum(int c) {
        long long limit=sqrt(c);
        for(int i=0;i<=limit;i++){
            long long sq=i*i;
            long long c2=c;
            long long cs=c2-sq;
            long long cn=sqrt(cs);
            long long acs=cn*cn;
            if(acs==cs)return true; 
        }
        return false;
        
    }
};