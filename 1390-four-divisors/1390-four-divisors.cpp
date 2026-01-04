class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            vector<long long> count;
            bool isvalid=true;
            for (int i = 1; i <=sqrt(nums[j]); i++) {
                if(i*i==nums[j])isvalid=false;
                if (nums[j] % i == 0)
                    count.push_back(i);
            }
            if(!isvalid)continue;
            if (count.size() == 2) {
                sum += count[0];
                sum += (nums[j] / count[0]);
                sum += count[1];
                sum += (nums[j] / count[1]);
            }
        }
        return sum;
    }
};