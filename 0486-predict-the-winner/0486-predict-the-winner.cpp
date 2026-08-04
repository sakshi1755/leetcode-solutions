class Solution {
public:
    bool dfs(vector<int>& nums,int si,int ei,int sum1,int sum2,int p){
        if(si>ei){
            return (sum1>=sum2);
        }
        if(p==0){
            int ft=dfs(nums,si+1,ei,sum1+nums[si],sum2,1);
            int lt=dfs(nums,si,ei-1,sum1+nums[ei],sum2,1);
            return ft|| lt;
        }
        else{
            int ft=dfs(nums,si+1,ei,sum1,sum2+nums[si],0);
            int lt=dfs(nums,si,ei-1,sum1,sum2+nums[ei],0);
            if(ft==false || lt==false)return false;
            else return true;

        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
      //  vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        return dfs(nums,0,n-1,0,0,0);
        
        
        
    }
};