class Solution {
public:
    int maximum69Number (int num) {
        vector<int>temp;
        int n=num;
        while(n>0){
           temp.push_back(n%10);
           n=n/10;
        }
         reverse(temp.begin(), temp.end());
        for(int i=0;i<temp.size();i++){
         if(temp[i]==6){
            temp[i]=9;
            break;
         }
            
        }
        int ans=0;
        for(int i=0;i<temp.size();i++){
            ans=ans*10+temp[i];
        }
        return ans;

        
    }
};