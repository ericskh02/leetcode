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
    void traversal(TreeNode* root, int mx, int mn){
        if(root==nullptr) return;
        int val = root->val;
        ans = max(ans,max(abs(mx-val),abs(val-mn)));
        mx = max(mx,val);
        mn = min(mn,val);
        traversal(root->left,mx,mn);
        traversal(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        traversal(root,root->val,root->val);
        return ans;
    }
};
