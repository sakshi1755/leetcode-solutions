class Solution {
public:
    int pivotInteger(int n) {
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
       // long long total=(n(n+1))/2
        int curr=2;
        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+curr;
            curr++;
        }
        suffix[n-1]=n;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+i+1;

        }
        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]){
                return i+1;
            }
        }
        return -1;

        
    }
};