class Solution {
public:
    int days(vector<int>& bloomDay, int m, int k){
        int n=bloomDay.size();
        vector<int>bloomed(n,0);
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=m)bloomed[i]=1;
        }
        int countc=0;
        int boq=0;
        for(int i=0;i<n;i++){
            if(bloomed[i]==1){
                countc++;
                if(countc==k){
                    boq++;
                    countc=0;

                }
            }
            else {
                countc=0;
            }
        }
        return boq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=1;
        int maxi=0;
        for(int i=0;i<n;i++)maxi=max(maxi,bloomDay[i]);
        int r=maxi;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int b=days(bloomDay,mid,k);
            if(b>=m){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        if(ans==0)return -1;
        return ans;


        
    }
};