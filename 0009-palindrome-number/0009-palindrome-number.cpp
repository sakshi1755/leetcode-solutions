class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int i=1;
        int n=x;
        long long int y=0;
        if(x/10==0)return true;
        while(n){
            int temp=n%(10);
            y=y*10+temp;
         
            n=n/10;


        }
        // if(x<0)y=-y;
        return y==x;
        
    }
};