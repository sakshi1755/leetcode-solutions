class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
       vector<bool> isnotp(right + 1, false);
        vector<int>a;
        for(int i=2;i<=right;i++){
            if(i>=left && !isnotp[i])a.push_back(i);
            for(int j=2*i;j<=right;j+=i){
                isnotp[j]=true;
            }
        }
        // sort(a.begin(),a.end());
        vector<int>ans(2,-1);
        int mini=INT_MAX;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]<mini){
                ans={a[i-1],a[i]};
                mini=a[i]-a[i-1];
            }
        }
        return ans;
        
        
    }
};