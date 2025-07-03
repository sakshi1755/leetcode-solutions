class Solution {
public:
    bool pali(vector<char>&modified,int l ,int r){
       int n=modified.size();
        if(n==0)return true;
        if(l==r)return true;
        if(l>r)return true;
        if(modified[l]!=modified[r])return false;
       // Removes first element

        return pali(modified,l+1,r-1);
    }
    bool isPalindrome(string s) {
        vector<char> modified;
        for(int i=0;i<s.size();i++){
           char ch=s[i];
            if(ch>=97 && ch<=122){
                modified.push_back(ch);
            }
            else if(ch>=65 && ch<=90){
                ch=ch+32;
                modified.push_back(ch);
            }
                else if (ch >= '0' && ch <= '9') {   // ✅ Allow digits
                modified.push_back(ch);
            }
        }
          int n=modified.size();
          int l=0;
          int r=n-1;
        return pali(modified, l, r);
        
    }
};