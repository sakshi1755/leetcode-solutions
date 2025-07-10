class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int m=n/3;
        sort(piles.begin(),piles.end());
        int i=n-2;
        int ans=0;
        while(m){
            ans+=piles[i];
            i=i-2;
            m--;

        }
        return ans;
        
    }
};