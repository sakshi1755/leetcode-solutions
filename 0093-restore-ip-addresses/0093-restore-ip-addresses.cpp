class Solution {
public:
    void solve(string &s,vector<string>&ans, int part, int ind, string path){
        if(part==4){
         if(ind==s.size()){
            path.pop_back();
            ans.push_back(path);
         }
         return;   
        }
        for(int i=1;i<=3;i++){
            if(ind+i>s.size())break;
            string curr=s.substr(ind,i);
            if(i>1 && curr[0]=='0')break;
            int num=stoi(curr);
            if(i>1 && num==0)break;
            if(num>255)break;
            string temp=path+curr+'.';
            solve(s,ans,part+1,ind+i,temp);
            
        }
    }
    vector<string> restoreIpAddresses(string s) {   
        vector<string> ans;
        string path="";
        solve( s,ans,0,0,path);
        return ans;




    }
};