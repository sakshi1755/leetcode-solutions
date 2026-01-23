class Solution {
public:
    long long countsteps(long long n,long long curr){
        long long next=curr+1;
        long long steps=0;
        while(curr<=n){
            steps+=min(n+1,next)-curr;
            curr*=10;
            next*=10;

        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        long long curr=1;
     
        while(k>0){
            long long  steps=countsteps(n,curr);
            if(steps<k){
                k-=steps;
                curr++;

            }
            else{
                  k--; 
                if(k>0)curr=curr*10;
              
                

            }
            


        }
        return curr;
        
    }
};