class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int end=n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                end=i;
                break;

            }

        }

        int ans=0;
        int beforei=0;
        for(int i=0;i<end;i++){
            if(s[i]=='1'){
                beforei++;
                if(s[i+1]=='0')ans=ans+beforei;
            }
        }
        return ans;


        
    }
};