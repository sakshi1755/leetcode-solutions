class Solution {
public:
    bool check(map<char,int>& map1, map<char,int> &map2){
        for(int i=0;i<26;i++){
            if(map2['a'+i]!=map1['a'+i])return false;
           
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(m<n)return false;
        map<char,int> map1;
        map<char,int> map2;
        for(int i=0;i<n;i++){
            map1[s1[i]]++;
        }
        for(int i=0;i<n;i++){
            map2[s2[i]]++;            
        }
        int l=0;
        int r=n-1;

        if(check(map1,map2))return true;
        l++;
        r++;
        while(r<m){
               map2[s2[l-1]]--;
               map2[s2[r]]++;
               if(check(map1,map2))return true;
               r++;
               l++;
        }
        return false;

    }
};