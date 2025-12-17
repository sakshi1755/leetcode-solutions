class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        while(s.size()<=k){
           
            int l=s.size();
            //string t=s;
            
            s+='1';

            for(int i=0;i<l;i++){
                if(i==l-1-i){
                     if(s[i]=='0')s+='1';
                else s+='0';
                }
               else{
                if(s[i]=='1')s+='1';
                else s+='0';

               };
               
            }

        }
        return s[k-1];
    }
};

//011
//0111
//l=3;i=2;0111