class Solution {
public:
    long long sumScores(string s) {
        int n=s.size();
        vector<long long>z(n,0);
        long long l=0;
        long long r=0;
        for(int i=0;i<n;i++){
            if(i>r){
                l=i;
                r=i;
                while(r<n && s[r]==s[r-l]){
                    r++;
                }
                z[i]=r-l;
                r--;



            }
            else{
                if(z[i-l]+i <=r){
                    z[i]=z[i-l];

                }
                else{
                    l=i;
                    while(r<n && s[r]==s[r-l])r++;
                    z[i]=r-l;
                    r--;

                }
            }
        }
        z[0]=n;
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=z[i];
        }
        return ans;
        
    }
};