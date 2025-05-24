// User function Template for C++

class Solution {
  public:
  
    static bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int>b){
        return a.first.second<b.first.second;
    }
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<pair<pair<int,int>,int>> meets;
        for(int i=0; i<N; i++){
            meets.push_back({{S[i], F[i]},i});
        }
        sort(meets.begin(), meets.end(), comp);
        vector<int>ans;
        pair<pair<int,int>,int>currmeet=meets[0];
         ans.push_back(currmeet.second+1);
        for(int i=1; i<N; i++){
            if(meets[i].first.first >currmeet.first.second){
       
               currmeet=meets[i];
               ans.push_back(currmeet.second+1);
            }
            
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
};