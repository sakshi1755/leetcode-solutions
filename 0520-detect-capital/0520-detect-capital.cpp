class Solution {
public:
    bool detectCapitalUse(string word) {
        //A is smaller than a
        int n=word.size();
        int count=0;
        int fc=-1;
        for(int i=0;i<n;i++){
            if(word[i]<'a'){count++;
            if(fc=-1)fc=i;
            }
        }
        return (count==n)||(count==1 && fc==0)||(count==0);
    }
};