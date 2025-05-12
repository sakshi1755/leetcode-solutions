class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set numset (nums.begin(), nums.end());
        int length=0;
        int longest=0;
        for (int num:numset ){
            if(numset.find(num-1)==numset.end()){
                length=1;
                int curr=num;
                while(numset.find(curr+1)!=numset.end()){
                    length++;
                    curr++;
                }
                longest=max(longest,length);
            }
        }
        return longest;   
    }
};