class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        bool negative=false;
        int ans=0;
       // vector<char>v;
       
            while(i<n && s[i]==' ')i++;
            
            if(i<n && s[i]=='-'){
                negative=true;
                i++;
            }
            else if(i<n && s[i]=='+'){
                negative=false;
                i++;
            }
            while(i<n && s[i]>=48 && s[i]<=57){
                if(ans>(INT_MAX-(s[i]-48))/10){
                    if(negative)return INT_MIN;
                    return INT_MAX;
                }
               ans=ans*10+(s[i]-48);
               
               i++;
            }
            

 
        
        if(negative)return -ans;
        return ans;
    }
};