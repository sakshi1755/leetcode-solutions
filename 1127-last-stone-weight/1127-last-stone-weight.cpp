class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        int n=stones.size();
        for(int i=0;i<n;i++)q.push(stones[i]);
        while(q.size()>1){
            int t1=q.top();
            q.pop();
            int t2=q.top();
            q.pop();
            if(t1!=t2){
                q.push(t1-t2);
            }
        } 
        if(!q.empty())return q.top();
        else return 0;
    }
};