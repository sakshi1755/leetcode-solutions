class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2)return false;
        map<char,char> m;
        map<char,bool>used;
        for(int i=0; i<n1;i++){
            int l=s[i];
            if(m.find(l)!=m.end()){
                if(m[s[i]]!=t[i])return false;
            }
            else{
               if(used[t[i]])return false;
                m[s[i]]=t[i];
                used[t[i]]=true;
              
              
            }
        }
        return true;



        
    }
};