class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int curr=0;
        int n=gain.size();
        for(int i=0;i<n;i++){
            curr=curr+gain[i];
            ans=max(ans,curr);
        }
        return ans;

    }
};