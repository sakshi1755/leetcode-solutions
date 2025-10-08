class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>ans(n,0);
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            a[i]=success/spells[i];
            if(success%spells[i]!=0){
                a[i]++;
            }
        }
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            auto it=lower_bound(potions.begin(),potions.end(), a[i]);
            if(it==potions.end()){
                ans[i]=0;
            }
            else{
                int ind=it-potions.begin();
                ans[i]=m-ind;
            }
        }
        return ans;

        
    }
};