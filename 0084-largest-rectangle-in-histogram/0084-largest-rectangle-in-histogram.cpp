class Solution {
public:
    vector<int> prevsmallelement(vector<int>& heights) {
        stack<int> s;
        int size = heights.size();
        vector<int> ans(size, -1); // Initialize to -1 for no previous smaller element

        for (int i = 0; i < size; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = (s.empty() ? -1 : s.top()); // Use index to find previous smaller element
            s.push(i); // Push the index
        }
        return ans;
    }

    vector<int> nextsmallelement(vector<int>& heights) {
        stack<int> s;
        int size = heights.size();
        vector<int> ans(size, size); // Initialize to size for no next smaller element

        for (int i = size - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            ans[i] = (s.empty() ? size : s.top()); // Use index to find next smaller element
            s.push(i); // Push the index
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        int area=0;
          vector<int> n=prevsmallelement( heights);
            vector<int> p=nextsmallelement( heights);
        for(int i=0;i<size;i++){
            int h=heights[i];
          
            int w=p[i]-n[i]-1;
            int newarea=h*w;
            area=max(area,newarea);

        }
        return area;

        
    }
};