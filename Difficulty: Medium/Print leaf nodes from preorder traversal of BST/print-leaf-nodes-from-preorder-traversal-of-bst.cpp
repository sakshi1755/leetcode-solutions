class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
     vector<int> leafNode;
        stack<int> s;
        int n = preorder.size();
        s.push(preorder[0]);
        for (int i = 1; i < n ; i++) {
            if (!s.empty() && preorder[i] < s.top()) {
                s.push(preorder[i]);
            } else {
                int temp = -1;
                if(!s.empty()) temp = s.top();
                int count=0;
                while (!s.empty() && preorder[i] > s.top()) {
                   count++;
                    s.pop();
                }
                if (temp != -1 && count>1) leafNode.push_back(temp); // temp was valid only if we popped
                s.push(preorder[i]); // don't forget to push the current element
            }
        }

        // Last node is always a leaf
        leafNode.push_back(preorder[n - 1]);

        return leafNode;
}
};