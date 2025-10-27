class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long n=bank.size();
        long long prev=0;
        for(int i=0;i<bank[0].size();i++){
            if(bank[0][i]=='1')prev++;
        }
       long long ans=0;
        for(int i=1;i<n;i++){
             long long curr=0;
            for(int j=0;j<bank[i].size();j++){
               if(bank[i][j]=='1') curr++;

            }
            ans=ans+(curr*prev);
            if(curr!=0)prev=curr;

        }
        return ans;
    }
};