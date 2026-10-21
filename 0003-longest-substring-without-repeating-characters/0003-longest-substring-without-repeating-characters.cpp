class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        map<char,int>freq;
        int ans=0;
        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }       
            ans=max(ans,r-l+1);     
            r++;
        }
        return ans;
        
        
    }
};