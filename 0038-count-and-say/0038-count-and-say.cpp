class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string temp=countAndSay(n-1);
        int m=temp.size();
        int i=0;
        string ans="";
        while(i<m){
            char x=temp[i];
            int count=1;
            while(i<m-1 && temp[i+1]==x){
                count++;
                i++;
            }

            ans.push_back('0'+count);
            ans.push_back(x);
            i++;


        }
        return ans;
    }
};