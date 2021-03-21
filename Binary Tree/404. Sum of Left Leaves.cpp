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
    int sum = 0;
    void traversal(TreeNode* root){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr &&root->left->left==nullptr && root->left->right==nullptr){
            sum += root->left->val;
        }
        traversal(root->left);
        traversal(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root);
        return sum;
    }
};
