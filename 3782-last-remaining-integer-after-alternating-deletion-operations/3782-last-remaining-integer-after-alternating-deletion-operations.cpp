class Solution {
public:
    long long lastInteger(long long n) {
        long long head=1;
        long long l=n;
        long long gap=1;
        while(l>1){
            l=(l+1)/2;
            gap+=gap;
            if(l<=1)break;
            
                
            if(l%2==0)    head=head+gap;
                gap+=gap;
                l=(l+1)/2;
            
        }
        return head;
    }
};