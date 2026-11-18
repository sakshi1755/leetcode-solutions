class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int unlocks=0;
        int n=nums.size();
        vector<int>smallsafter(n+1,0);
        vector<int>smallsbefore(n+1,0);
        vector<int>pos(n+1,0);
        for(int i=0;i<n;i++){
            int val=nums[i];
            pos[val]=i;
            for(int j=0;j<i;j++){
                if(nums[j]<val)smallsbefore[val]++;
            }
            for(int j=i+1;j<n;j++){
                if(nums[j]<val)smallsafter[val]++;
            }
        }
        for(int i=0;i<n;i++){
            if((nums[i]!=i+1 || smallsafter[nums[i]]) && locked[i])unlocks++;
        }
        if(unlocks>k)return -1;
        else{
            int swaps=0;
            for(int i=1;i<=n;i++){
                int ip=pos[i];
                int cp=pos[i]+smallsafter[i];
                int posneeded=i-1;
                swaps+=(cp-posneeded);


            }
         int ans=unlocks+swaps;
         return ans;  
        }

       
        
    }
};

//  1 2 4 3   1  2 4  3      
//  2 3 1 5
//  1 2 3 4
//  1 2 5 6 7 4
//  4 1 2 3

// 1 4 3 2
// 1 2 4 3
// 3 4 5 1