class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0){
                    if(st.top()<abs(asteroids[i]))st.pop();
                    else break;
                }
                if(st.empty()|| st.top()<0)st.push(asteroids[i]);
                if(st.top()==abs(asteroids[i]))st.pop();
            }
        }
        vector<int>ans;
        int sn=st.size();
        for(int i=0;i<sn;i++){
            ans.push_back(st.top());
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};