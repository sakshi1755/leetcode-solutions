class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=a.size();
        int n=b.size();
        if(m==n){
            if(a==b)return 1;
        }
        int count=1;
        string tempa=a;
        while(a.size()<b.size()){
            a=a+tempa;
            count++;
        }
        if(a.find(b) != string::npos)return count;
        else{
            a=a+tempa;
            count++;
            if(a.find(b) != string::npos)return count;

        }
        return -1;
        
        
        
    }
};