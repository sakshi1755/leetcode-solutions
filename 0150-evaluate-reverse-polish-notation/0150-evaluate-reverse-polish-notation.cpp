class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        set<string> s={"*","+","-","/"};
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(s.count(tokens[i])==0){
                st.push(stoi(tokens[i]));
                
            }
            else{
                int t2=st.top();
                st.pop();
                int t1=st.top();
                st.pop();
                if(tokens[i]=="*"){
                    st.push(t1*t2);
                }
                else if(tokens[i]=="/"){
                    st.push(t1/t2);
                }
                else if(tokens[i]=="-"){
                    st.push(t1-t2);
                }
                else st.push(t1+t2);
            }
        }
        return st.top();
        
    }
};