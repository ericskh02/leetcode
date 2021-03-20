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
    TreeNode* ans = new TreeNode();
    TreeNode* curr = ans;
    void traversal(TreeNode* root){
        if(root==nullptr) return;
        traversal(root->left);
        TreeNode* temp = new TreeNode(root->val);
        curr->right = temp;
        curr = curr->right;
        traversal(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        traversal(root);
        return ans->right;
    }
};
