class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        bool isansun = true;

        for (int i = 0; i < n; i++) {
            int newtarget = target - nums[i];
            set<int> s;

            for (int j = i + 1; j < n; j++) {
                int need = newtarget - nums[j];

                if (!s.empty()) {
                    auto it = s.lower_bound(need);

                    // candidate from lower_bound
                    if (it != s.end()) {
                        int tempans = nums[i] + nums[j] + *it;
                        if (isansun || abs(target - tempans) < abs(target - ans)) {
                            ans = tempans;
                            isansun = false;
                        }
                    }

                    // candidate from lower_bound - 1
                    if (it != s.begin()) {
                        int tempans = nums[i] + nums[j] + *prev(it);
                        if (isansun || abs(target - tempans) < abs(target - ans)) {
                            ans = tempans;
                            isansun = false;
                        }
                    }
                }

                // VERY IMPORTANT: insert AFTER using
                s.insert(nums[j]);
            }
        }
        return ans;
    }
};
