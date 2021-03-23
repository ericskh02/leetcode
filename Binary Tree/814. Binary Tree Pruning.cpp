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
    int treesum(TreeNode* root){
        if(root==nullptr) return 0;
        int left = treesum(root->left);
        int right = treesum(root->right);
        if(left==0){
            root->left = nullptr;
        }
        if(right==0){
            root->right = nullptr;
        }
        return left + right + root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(treesum(root)==0) return nullptr;
        return root;
    }
};
