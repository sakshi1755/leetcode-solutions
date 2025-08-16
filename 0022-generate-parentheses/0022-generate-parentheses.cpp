class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string>res;
        makeonepara(n,open,close,"",res);
        return res;
        
    }

    void makeonepara(int n,int open,int close,string s,vector<string>&res){
        if(open==close && open+close==2*n)res.push_back(s);
        else{
            if(open<=n){
                
                
                makeonepara(n,open+1,close,s+'(',res);

            }
            if(close<open)makeonepara(n,open,close+1,s+')',res);
        }
    }
};