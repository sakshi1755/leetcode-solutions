class Solution {
public:
    int smallestNumber(int n) {
        int msb=31-__builtin_clz(n);
        int ans=1;
        int s=1;
        for(int i=0;i<=msb;i++){
            ans=ans| s;
            s=s<<1;
            
        }
        return ans;

    }
};