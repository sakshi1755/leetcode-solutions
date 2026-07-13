class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int ns=s.length();
        int nt=t.length();
        if(ns>nt)return false;
        vector<int>pref(ns,-1);
        vector<int>suff(ns,-1);
        int i=0;
        int j=0;
        while(i<ns && j<nt){
            if(s[i]==t[j]){
                pref[i]=j;
                i++;
                j++;
            }
            else j++;
        }
         i=ns-1;
         j=nt-1;
        while(i>=0 && j>=0){
            if(s[i]==t[j]){
                suff[i]=j;
                i--;
                j--;
            }
            else j--;
        }
        if(ns==1){
            return true;
        }
        if(pref[ns-1]!=-1)return true;
        for(int i=0;i<ns;i++){
            if(i==0 && i+1<ns){
                if(suff[i+1]>0)return true;
            }
            else if(i==ns-1 && i>0){
                if(pref[i-1]!=-1 && pref[i-1]<nt-1)return true;
            }
            else{
                if(pref[i-1]==-1 || suff[i+1]==-1)continue;
                if(pref[i-1]+1<suff[i+1])return true;
            }
        }
        return false;
           

        
        
    }
};