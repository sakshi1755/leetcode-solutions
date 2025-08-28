class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m=mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=m){
                m=m+asteroids[i];
            }
            else return false;
        }
        return true;
        
    }
};