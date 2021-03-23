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
    void traversal(TreeNode* root,int mx){
        if(root==nullptr) return;
        if(root->val>=mx) ans++;
        mx = max(mx,root->val);
        traversal(root->left,mx);
        traversal(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        traversal(root,root->val);
        return ans;
    }
};
