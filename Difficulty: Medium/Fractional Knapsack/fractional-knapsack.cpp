// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
          struct CompareSecond {
    bool operator()(pair<double,double> &a, pair<double,double> &b) {
        return a.second < b.second;  // "less" means max at top
    }
};
        double curr=0;
        double ans=0;
        priority_queue<pair<double,double>, vector<pair<double,double>>, CompareSecond> pq;
        int n=wt.size();
        for(int i=0;i<n;i++){
         double temp = (double)val[i] / wt[i];

            pq.push({wt[i],temp});
        }
        while(curr<=capacity && !pq.empty()){
            pair<double,double>t=pq.top();
            pq.pop();
            if(t.first<=(capacity-curr)){
               ans+= (t.first*t.second);
               curr+=t.first;
            }
            else{
                double fw=capacity-curr;
                ans+=(fw*t.second);
                curr+=fw;
            }
        }
        return ans;
        
    }
};


