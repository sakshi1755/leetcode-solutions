class Solution {
public:

   void solve(string &s, int st, int e, string& ans){
            int i=st;
            while(i<=e){
            int r=0;
            while(s[i]>='0' && s[i]<='9'){
                r=r*10+(s[i]-'0');
                i++;
                
            }
            if(r==0){
                ans.push_back(s[i]);
                i++;
            }
            
            else{
                //i++;
            stack<char>y;
            y.push(s[i]);
            i++;
            int ns=i;
            while(!y.empty()){
                if(s[i]=='[')y.push(s[i]);
                if(s[i]==']')y.pop();
                i++;
            }
            for(int j=0;j<r;j++)
            solve(s,ns,i-2,ans);


            }
           
        }
   }
    string decodeString(string s) {
        int n=s.size();
        string ans="";
        int i=0;
        solve(s,0,n-1,ans);
        return ans; 
    }
};