class Solution {
public:
    int romanToInt(string s) {
        map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i<n-1 && s[i]=='I' && s[i+1]=='V'){ ans+=4; i++;}
            else if(i<n-1 && s[i]=='I' && s[i+1]=='X'){ ans+=9; i++;}
            else if(i<n-1 && s[i]=='X' && s[i+1]=='L'){ ans+=40; i++;}
            else if(i<n-1 && s[i]=='X' && s[i+1]=='C'){ ans+=90; i++;}     
            else if(i<n-1 && s[i]=='C' && s[i+1]=='D'){ ans+=400; i++;}      
            else if(i<n-1 && s[i]=='C' && s[i+1]=='M'){ ans+=900;  i++;}               
            else ans+=m[s[i]];
        }
        return ans;
        
    }
};