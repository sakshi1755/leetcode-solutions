class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        map<int,bool>shouldremove;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push({s[i],i});
            if(s[i]==')'){
                if(st.empty()){
                    shouldremove[i]=true;
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            shouldremove[st.top().second]=true;
            st.pop();
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(!shouldremove[i])ans.push_back(s[i]);
        }
        return ans;
    }
};