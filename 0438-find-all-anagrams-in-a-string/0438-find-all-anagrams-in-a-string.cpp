class Solution {
public:
     bool check(map<char,int>& map1, map<char,int> &map2){
        for(int i=0;i<26;i++){
            if(map2['a'+i]!=map1['a'+i])return false;
           
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        int m=s.size();
         if(m<n)return {};
        map<char,int> map1;
        map<char,int> map2;
        for(int i=0;i<n;i++){
            map1[p[i]]++;
        }
        for(int i=0;i<n;i++){
            map2[s[i]]++;
        }
         vector<int>ans;
        int l=0;
        int r=n-1;

        if(check(map1,map2)) ans.push_back(l);
        l++;
        r++;
        while(r<m){
               map2[s[l-1]]--;
               map2[s[r]]++;
               if(check(map1,map2)) ans.push_back(l);
               r++;
               l++;
        }
        return ans;

    
       
        
        
    }
};