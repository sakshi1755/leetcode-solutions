class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        int maxi=INT_MIN;
        // set<int>s;
        map<int,int>freq;
        for(int i=0;i<n;i++){
           nums[i] = ((nums[i] % value) + value) % value;

            freq[nums[i]]++;
            nums[i]=nums[i]+(freq[nums[i]]-1)*value;
            maxi=max(maxi,nums[i]);
            // s.insert(nums[i]);
        }
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if(nums[i]!=i){
            return i;
        }

       }


      return maxi+1;
    }
};