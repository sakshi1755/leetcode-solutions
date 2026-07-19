class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        stack<int>st;
        map<char,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        map<char,bool>taken;
        for(int i=0;i<n;i++){
            freq[s[i]]--;
            if(taken[s[i]])continue;
            while(!st.empty()){
                int t=st.top();
                if(s[i]<t){
                    if(freq[t]>0){st.pop();
                    taken[t]=false;
                    }
                    else break;
                }
                else break;
            }
            st.push(s[i]);
            taken[s[i]]=true;
            
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};