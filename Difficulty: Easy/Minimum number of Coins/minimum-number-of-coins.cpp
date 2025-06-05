// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        priority_queue<int> pq;
        vector<int> vals = {2000,500,200,100,50,20,10,5,2,1};
    vector<int> ans;
    int i=0;
      while(N>0|| i<10 ){
            if(vals[i]<=N){
                  N=N-vals[i];
                  ans.push_back(vals[i]);
            }
            else{
              i++;  
            }
        }
        return ans;
          
        
    }
};