class Solution {
public:
    bool ispossible(string &ans, string str1, string str2){
        string temp=ans;
        int n=str1.size();
        int m=str2.size();
        while(temp.size()<n){
            temp=temp+ans;
        
        }
        if(temp!=str1)return false;
        temp=ans;
        while(temp.size()<m){
            temp=temp+ans;
        
        }
        if(temp!=str2)return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int n=min(str1.size(),str2.size());
        for (int i = 0; i < n; i++) {
            if (str1[i] == str2[i]) {
                ans.push_back(str1[i]);

            } else
                break;
        }
        while(ans!="" && !ispossible(ans,str1, str2) )ans.pop_back();
        return ans;
    }
};