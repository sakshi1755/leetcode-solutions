class Solution {
public:
    struct cmp {
        int k;
        cmp(int kk){ k = kk; }
        bool operator()(int a, int b) {
            if (abs(a-k) == abs(b-k)) return a < b; // prefer smaller value
            return abs(a-k) < abs(b-k);  // max-heap of closest elements
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, cmp> pq((cmp(x)));
        
        for(int num : arr) {
            pq.push(num);
            if(pq.size() > k) pq.pop();  // keep only k closest
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
