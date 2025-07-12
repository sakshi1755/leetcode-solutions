class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int mp=(1<<n);
          vector<vector<int>> subset;
        for(int i=0;i<mp;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(i & (1<<j)) temp.push_back(nums[j]);

            }
            subset.push_back(temp);
        }
        return subset;
        
    }
};