class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sh=1;
        vector<int>ans;
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]==2)ans.push_back(nums[i]);
          
        }
        for(int i=1;i<=n;i++){
            if(m[i]==0){
                ans.push_back(i);
                break;
            }

        }
       
        return ans;
    }
};