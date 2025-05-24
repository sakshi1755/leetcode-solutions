class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
     static bool comp(pair<int,int> a, pair<int,int>b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        // Your code here
        int N=start.size();
        if(N==0)return 0;
         vector<pair<int,int>> meets;
        for(int i=0; i<N; i++){
            meets.push_back({start[i], end[i]});
        }
        sort(meets.begin(), meets.end(), comp);
       int count =1;
        pair<int,int> currmeet=meets[0];
        for(int i=1; i<N; i++){
            if(meets[i].first>currmeet.second){
              
               currmeet=meets[i];
                 count++;
            }
            
        }
        return count;
        
        
    }
    
};