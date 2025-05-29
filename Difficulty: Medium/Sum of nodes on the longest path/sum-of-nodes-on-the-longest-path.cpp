/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  pair<int,int>solve(Node *root){
      if(root==nullptr)return {0,0}; //{count,sum}
      else{
          auto left = solve(root->left);
        auto right = solve(root->right);
        if(left.first==right.first) {
         if(left.second>right.second){ int count=left.first+1;
            int sum=left.second+root->data;
            return{count,sum};
         }
         else{ 
           int count=right.first+1;
            int sum=right.second+root->data;
             return{count,sum};
         }
      }
      if(left.first>right.first){
          int count=left.first+1;
            int sum=left.second+root->data;
            return{count,sum};
          
      }
      else{
          int count=right.first+1;
            int sum=right.second+root->data;
             return{count,sum};
          
      }
        
        
          
      }
      
  }
  
    int sumOfLongRootToLeafPath(Node *root) {
      
        int ans=solve(root).second;
        return ans;
        }
    
};