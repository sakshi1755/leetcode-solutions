class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            if(possible[i]==0)possible[i]=-1;
            sum+=possible[i];
        }
        int ans=-1;
        long long curr=0;
        for(int i=0;i<n-1;i++){
            curr+=possible[i];
            long long bob=sum-curr;
            if(curr>bob){
                ans=i+1;
                break;
            }

        }
        return ans;        
    }
};