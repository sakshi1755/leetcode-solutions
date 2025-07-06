class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=n-1;
        string result="";
        while(i>=0){
            while(i>=0 && s[i]==' ')i--;
             if (i < 0) break;
            int j=i;
            while(j>=0 && s[j]!=' ')j--;
           if(!result.empty()) result=result+" "+s.substr(j+1,i-j);
           else result=s.substr(j+1,i-j);
            i=j-1;



        }
        return result;
        
    }
};