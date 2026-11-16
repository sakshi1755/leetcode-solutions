class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        if(n<=k)return s;
        else{
            string ans="";
            string temp="";
            int sum=0;
            for(int i=0;i<n;i++){
                if((i+1)%k==0){
                    sum+=(s[i]-'0');
                    temp=to_string(sum);
                    ans+=temp;
                    sum=0;

                }
                else{
                    sum+=(s[i]-'0');

                }
            }
            if(n%k!=0){temp=to_string(sum);
            ans+=temp;}
            return digitSum(ans,k);
        }

        
    }
};