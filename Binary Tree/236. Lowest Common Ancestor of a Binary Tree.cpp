/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool traversal(TreeNode* root,TreeNode* p ,TreeNode* q){
        if(root==nullptr) return false;
        bool left = traversal(root->left,p,q);
        bool right = traversal(root->right,p,q);
        bool self = (root==p || root==q) ? true : false;
        if (left && right || self && left || self && right) {
            ans = root;
            return false;
        }
        return left||right||self;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traversal(root,p,q);
        return ans;
    }
};
