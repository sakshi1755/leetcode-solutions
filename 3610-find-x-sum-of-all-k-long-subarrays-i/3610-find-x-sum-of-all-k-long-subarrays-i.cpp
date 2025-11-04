class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int,int>f;
        priority_queue<pair<int,int>>p;
        int i=0;
        int n=nums.size();
        for(i=0;i<k-1;i++){
            f[nums[i]]++;
        }
        vector<int>ans(n-k+1);
        int start=-1;
        int j=0;
        while(i<n){
            f[nums[i]]++;
            if(start>=0){
                f[nums[start]]--;                   // ✅ fix: remove outgoing element
                if(f[nums[start]]==0)f.erase(nums[start]);
            }

            // ✅ fix: correct syntax and clear priority_queue
            while(!p.empty()) p.pop();
            for(auto it : f){                       // ✅ fix: use ':' not ':'
                p.push({it.second,it.first});
            }

            int cnt=0;                              // ✅ fix: rename k -> cnt
            while(cnt<x && !p.empty()){             // ✅ fix: use '&&'
                int t=p.top().first;
                int t2=p.top().second;
                p.pop();
                ans[j]+=(t*t2);
                cnt++;                              // ✅ fix: increment counter
            }

            i++;
            start++;
            j++;
        }
        return ans;
    }
};
