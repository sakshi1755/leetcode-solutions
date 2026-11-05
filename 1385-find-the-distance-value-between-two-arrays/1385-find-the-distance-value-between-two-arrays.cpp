class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        int n=arr1.size();
        int n2=arr2.size();
        for(int i=0;i<n;i++){
            int ind=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
            int ind2=ind-1;
            bool isok=true;
            if(ind<n2){
                if(arr2[ind]-arr1[i]<=d)isok=false;

            }
            if(ind2>=0){
                if(arr1[i]-arr2[ind2]<=d)isok=false;
            }
            if(isok)ans++;
        }
        return ans;
    }
};