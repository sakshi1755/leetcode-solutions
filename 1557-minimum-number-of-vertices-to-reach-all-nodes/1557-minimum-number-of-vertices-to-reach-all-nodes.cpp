class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int,bool>isr;
        for(int i=0;i<edges.size();i++){
            isr[edges[i][1]]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!isr[i])ans.push_back(i);
        }
        return ans;
        
    }
};

//
//
//