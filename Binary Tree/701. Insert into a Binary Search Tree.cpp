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
    void traversal(TreeNode* curr, int val){
        if(val<curr->val){
            if(curr->left==nullptr){
                curr->left = new TreeNode(val);
                return;
            }
            traversal(curr->left,val);
        } else {
            if(curr->right==nullptr){
                curr->right = new TreeNode(val);
                return;
            }
            traversal(curr->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        traversal(root,val);
        return root;
    }
};
