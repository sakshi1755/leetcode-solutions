class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int,int>>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back({arr[i],dep[i]});
        }
      
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.first< b.first;
    });
     vector<pair<int,int>>p;
     p.push_back(v[0]);
       for(int i=1;i<n;i++){
           int break1=0;
           int pb=1;
          for(int j=0;j<p.size();j++){
        if ((p[j].second<v[i].first)){
            p[j]=v[i];
            pb=0;      
    
           break;
        }   
        
        
           }
          
          if(pb) p.push_back(v[i]); 
    //       sort(p.begin(), p.end(), [](pair<int, int> &a, pair<int, int> &b) {
    //     return a.second < b.second;
    // });
//     sort(p.begin(), p.end(), [](pair<int, int> &a, pair<int, int> &b) {
//     return a.first < b.first;
// });
       }
       
    return p.size();
    }
};
