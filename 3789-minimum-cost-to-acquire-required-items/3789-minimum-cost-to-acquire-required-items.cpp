class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(costBoth<=cost1 && costBoth<=cost2){
            int bothused=min(need1,need2);
            ans=1LL*bothused*costBoth;
            ans+=(1LL*(need1-bothused)*costBoth);
            ans+=(1LL*(need2-bothused)*costBoth);

        }
        else if(costBoth>cost1 && costBoth<=cost2){
            ans=1LL*need2*costBoth;
            if(need2<need1)ans+=1LL*(need1-need2)*cost1;
        }
        else if(costBoth>cost2 && costBoth<=cost1){
            ans=1LL*need1*costBoth;
            if(need1<need2)ans+=1LL*(need2-need1)*cost2;
        }
        else{
            if(costBoth<=cost1+cost2){
                int bothused=min(need1,need2);
                ans=1LL*bothused*costBoth;
                ans+=(1LL*(need1-bothused)*cost1);
                ans+=(1LL*(need2-bothused)*cost2);
            }
            else{
                ans=1LL*cost1*need1;
                ans+=(1LL*cost2*need2);
            }
        }
        return ans;
        
    }
};