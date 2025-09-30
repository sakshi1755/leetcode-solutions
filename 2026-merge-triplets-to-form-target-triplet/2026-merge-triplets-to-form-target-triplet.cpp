class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        int ans1=0;
        int ans2=0;
        int ans3=0;
        for(int i=0;i<n;i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                ans1=max(ans1,triplets[i][0]);
                ans2=max(ans2,triplets[i][1]);
                ans3=max(ans3,triplets[i][2]);
            }
        }
        if(ans1==target[0] && ans2==target[1] && ans3==target[2])return true;
        else return false;
        
    }
};