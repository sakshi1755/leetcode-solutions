class Solution {
public:
    string reverseVowels(string s) {
       set<char>st={'A','a','E','e','I','i','O','o','U','u'};
       vector<char>v;
       int n=s.size();
       for(int i=0;i<n;i++){
        if(st.count(s[i])){
            v.push_back(s[i]);
        }
       }
       int size=v.size();
       for(int i=0;i<n;i++){
          if(st.count(s[i])){
            s[i]=v[size-1];
            v.pop_back();
            size--;
        }
       }
       return s;
        
    }
};