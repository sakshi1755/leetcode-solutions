class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        if(n==1)return target[0]==1;
        priority_queue<long long>q;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=target[i];
            q.push(target[i]);
        }
        while(sum>=n){
            if(sum==n)return true;
            long long t=q.top();
            q.pop();
            sum-=t;
            if(sum>=t)return false;
            long long r=t%sum;

            if(r==0)r=sum;
            //if(r==0 && sum==t)return false;
            q.push(r);
            sum+=r;
        }
        return false;
        
        
    }
};

