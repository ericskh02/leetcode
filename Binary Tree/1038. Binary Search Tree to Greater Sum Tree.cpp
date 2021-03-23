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
    void traversal(TreeNode* curr){
        if(curr==nullptr) return;
        traversal(curr->right);
        curr->val += sum;
        sum = curr->val;
        traversal(curr->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        traversal(root);
        return root;
    }
};
