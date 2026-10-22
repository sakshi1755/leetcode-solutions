class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int n=s.size();
        int j=n-1;
        int skip=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;

            }
            else if(skip==0){
                i++;
                skip++;


            }
            else break;
            
        }
        if(i==j || i>j)return true;
        i=0;
        j=n-1;
        skip=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;

            }
            else if(skip==0){
                j--;
                skip++;

            }
            else break;
        }
        if(i==j || i>j)return true;
        return false;
    }
};


 