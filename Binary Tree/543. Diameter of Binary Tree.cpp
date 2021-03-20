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
    int mx = 0;
    int traversalDiameter(TreeNode* root,int depth){
        if(root==nullptr)return depth;
        depth++;
        int left = traversalDiameter(root->left,depth);
        int right = traversalDiameter(root->right,depth);
        mx = max(mx,left+right-depth*2);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traversalDiameter(root,-1);
        return mx;
    }
};
