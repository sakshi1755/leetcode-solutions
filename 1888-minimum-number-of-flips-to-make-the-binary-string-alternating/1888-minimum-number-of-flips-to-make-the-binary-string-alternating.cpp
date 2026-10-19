class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        string s1="";
        string s2="";
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                s1+='1';
                s2+='0';
            }
            else{
                s1+='0';
                s2+='1';
            }
        }
        vector<int>prefix1(2*n+1,0);
        vector<int>prefix2(2*n+1,0);
        for(int i=0;i<2*n;i++){
            prefix1[i+1]=prefix1[i];
            prefix2[i+1]=prefix2[i];
            if(s1[i]!=s[i])prefix1[i+1]++;
            if(s2[i]!=s[i])prefix2[i+1]++;
        }
        int ans=INT_MAX;
        int j=0;
        for(int i=n-1;i<2*n;i++){
            ans=min(ans,prefix1[i+1]-prefix1[j]);
            ans=min(ans,prefix2[i+1]-prefix2[j]);
            j++;
        }
        return ans;

        

        
    }
};

// 11100011100
// 10101010101