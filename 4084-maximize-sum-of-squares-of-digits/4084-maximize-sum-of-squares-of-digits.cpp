class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num<sum)return "";
        string ans(num,'0');
        int i=0;
        while(sum>0){
            int dig=min(9,sum);
            sum=sum-dig;
           // char temp=dig+'0';
            ans[i]='0'+dig;
            i++;

            
        }
      
        return ans;
        
    }
};