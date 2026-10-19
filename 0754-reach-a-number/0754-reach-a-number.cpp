class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0;
        for(int i=1;i<=2*target;i++){
            sum+=i;
            if(sum>=target){
                int delta=sum-target;
                if(delta%2==0)return i;
            }

        }
        return -1;
        
    }
};

