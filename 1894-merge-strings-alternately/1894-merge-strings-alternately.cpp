class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        string ans(n + m, '\0');
        int l=0;
        int l2=0;
        int i=0;
        while(l<n && l2<m){
            if(i%2==0){
                ans[i]=word1[l];
                i++;
                l++;


            }
            else{
                ans[i]=word2[l2];
                i++;
                l2++;

            }

        }
        while(l<n){
            ans[i]=word1[l];
            i++;
            l++;
        }
        while(l2<m){
            ans[i]=word2[l2];
            i++;
            l2++;
        }
        return ans;

        
    }
};