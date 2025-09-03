/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* insertIntoBST2(TreeNode* root, int val,TreeNode* head) {
 if(val>root->val){
            if(root->right==nullptr){
                TreeNode* is=new TreeNode(val);
                root->right=is;
                return head;

            }
            else{
                return insertIntoBST2(root->right,val,head);
            }
        }
        else{
            if(root->left==nullptr){
                TreeNode* is=new TreeNode(val);
                root->left=is;
                return head;

            }
            else{
                return insertIntoBST2(root->left,val,head);
            }

        }
}

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* head=root;
        if(head==nullptr){
            head=new TreeNode(val);
            return head;
        }
        return insertIntoBST2(root,val,head);

       
        
    }
};