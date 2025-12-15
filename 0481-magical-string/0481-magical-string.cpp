class Solution {
public:
    int magicalString(int n) {
       string s="1221121221221121122";
       int l=s.size();
       int i=12;
       char al='1';
       while(s.size()<n){
        int cnt = s[i] - '0';
       for(int j=0;j<cnt;j++ ){
        s+=al;
       }
        if(al=='1')al='2';
        else al='1';
        i++;

       }
       int ans=0;
       for(int k=0;k<n;k++){
        if(s[k]=='1')ans++;
       }
       return ans;
    }
};


