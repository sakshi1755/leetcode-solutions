class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<int,int>,int>slope;
        int ans=0;
        int n=points.size();

        for(int i=0;i<n;i++){
            slope.clear();
            for(int j=0;j<n;j++){
                if(i!=j){
                    int dx=points[i][0]-points[j][0];
                    int dy=points[i][1]-points[j][1];
                    int g=gcd(dx,dy);
                    dx=dx/g;
                    dy=dy/g;
                    slope[{dy,dx}]++;
                    ans=max(ans, 1+slope[{dy,dx}]);
                  
                }
            }
        }
        return ans;
        
    }
};