class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxi=INT_MIN;
        int cuc=0;
        while(r<n ){
            if(s[l]==s[r]){
                cuc++;
                maxi=max(cuc,maxi);
                r++;
            }
            else{
                l=r;
                cuc=0;
            }
        }
        return maxi;
        

        
    }
};