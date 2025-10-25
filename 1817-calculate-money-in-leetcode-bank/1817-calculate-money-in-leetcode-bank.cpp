class Solution {
public:
    int totalMoney(int n) {
        int s=1;
        int ans=0;
        for(int i=n;i-7>=0;i=i-7){
            ans=ans+7*s+21;
            s++;
            n=n-7;

        }
        for(int i=0;i<n;i++){
            ans+=s+i;
        }
        return ans;
        
    }
};