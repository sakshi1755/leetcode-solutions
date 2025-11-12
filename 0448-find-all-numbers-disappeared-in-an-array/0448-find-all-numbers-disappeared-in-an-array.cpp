class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int sh=1;
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=sh){
                if(nums[i]>sh){ans.push_back(sh);
                sh++;
                i--;
                }
            }
            else sh++;
        }
        cout<<nums[n-1];
      //  if(nums[n-1]!=n)ans.push_back(n);
      for(int i=nums[n-1]+1;i<=n;i++){
        ans.push_back(i);
      }
        return ans;
        
    }
};