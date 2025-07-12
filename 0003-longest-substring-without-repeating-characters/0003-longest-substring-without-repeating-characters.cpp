class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        map<char,int>freq;
        int ans=0;
        int n=s.size();
        // freq[s[0]]++;
        // r++;
        ans=0;
        int size=0;
        while(r<n){
          if(freq[s[r]]==0){
            size++;
            ans=max(ans,size);
              freq[s[r]]=freq[s[r]]+1;
            r++;
          
          }
          else if(l<n){
             freq[s[l]]=freq[s[l]]-1;
            l++;
            size--;
        
          }  
          else break;
        
        }
        return ans;
    }
};