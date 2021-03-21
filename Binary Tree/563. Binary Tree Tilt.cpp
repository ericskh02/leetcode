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
    int ans = 0;
    int sum(TreeNode* root){
        if(root==nullptr) return 0;
        root->val = root->val + sum(root->left) + sum(root->right);
        return root->val;
    }
    void traversal(TreeNode* root){
        if(root==nullptr) return;
        traversal(root->left);
        traversal(root->right);
        if(root->left==nullptr && root->right==nullptr){
            
        } else if(root->left==nullptr){
            ans += abs(root->right->val);
        } else if(root->right==nullptr){
            ans += abs(root->left->val);
        } else {
            ans += abs(root->left->val - root->right->val);
        }
    }
    int findTilt(TreeNode* root) {
        sum(root);
        traversal(root);
        return ans;
    }
};
