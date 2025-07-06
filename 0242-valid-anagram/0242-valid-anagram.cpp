class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2)return false;
        map<char,int>m1;
        map<char,int>m2;

        for(int i=0;i<n1;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(int i=0;i<n2;i++){
            if(m1[s[i]]!=m2[s[i]])return false;
        }
        return true;
        
    }
};