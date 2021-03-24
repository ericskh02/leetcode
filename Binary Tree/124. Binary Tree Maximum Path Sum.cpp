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
    int ans = INT_MIN;
    int pathSum(TreeNode* root){
        if(root==nullptr) return 0;
        int left = max(pathSum(root->left),0);
        int right = max(pathSum(root->right),0);
        int sum = left + right + root->val;
        ans = max(ans,sum);
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return ans;
    }
};
