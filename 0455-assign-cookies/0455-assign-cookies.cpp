class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
         int j=0;
         int m=s.size();
         int n=g.size();
         int count=0;
        for(int i=0;i<n&& j<m;i++){
           
            if(s[j]>=g[i]){
                count++;
                j++;
            }
        }
        return count;
    }
};