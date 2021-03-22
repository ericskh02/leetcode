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
    TreeNode* ans = nullptr;
    bool traversal(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return false;
        bool leftFound = traversal(root->left,p,q);
        bool rightFound = traversal(root->right,p,q);
        bool currFound = (root==p || root==q);
        if((leftFound && rightFound) || (leftFound && currFound) || (rightFound && currFound)){
            ans = root;
            return false;
        }
        return leftFound || rightFound || currFound;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traversal(root,p,q);
        return ans;
    }
};
