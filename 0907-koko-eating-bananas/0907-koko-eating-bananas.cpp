class Solution {
public:
    long long noofhours(vector<int>& piles, int mid){
        int c=mid-1;
        long long ans=0;
        for(int i=0;i<piles.size();i++){
           ans=ans+(piles[i])/mid;
           if(piles[i]%mid!=0)ans++;

        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long l=1;
        long long n=piles.size();

        long long r=piles[n-1];
        long long ans=r;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long noh=noofhours(piles,mid);
            if(noh<=h){
                ans=min(ans,mid);
                  r=mid-1;
            }
            else{
              
                l=mid+1;
            }
        }

        return ans;

        
    }
};