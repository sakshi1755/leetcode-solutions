class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        long long ans=0;
        int n=s.size();
        int is=0;
        int ie=n-1;
        while(is<n && s[is]!='0'){
            is++;
        }
        if(is==n)return n;
        while(ie>=0 && s[ie]!='0' ){
            ie--;
        }
        if(ie<0)return n;
        ans=is+(n-1-ie);
        long long bz=0;
        long long cz=0;
        long long co=0;
        long long bo=0;
        long long as=0;
        int to=0;
        for(int i=is;i<=ie;i++){
            if(s[i]=='1'){
                to++;
                if(co!=0)co++;
                else{
                  if(bo!=0)  as=max(as,bz+cz);
                    bz=cz;
                    cz=0;
                    co++;
                }

            }
            else{
                if(cz!=0)cz++;
                else{
                    
                    bo=co;
                    co=0;
                    cz++;

                }
            }

        }
          if(bo!=0)  as=max(as,bz+cz);
            ans+=as;
            ans+=to;
            return ans;

        
        
    }
};