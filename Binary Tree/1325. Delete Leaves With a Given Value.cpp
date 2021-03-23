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
    bool deleteTraversal(TreeNode* root, int target){
        if(root==nullptr) return false;
        if(deleteTraversal(root->left,target)){
            root->left = nullptr;
        }
        if(deleteTraversal(root->right,target)){
            root->right = nullptr;
        }
        if(root->val==target && root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* dummy = new TreeNode();
        dummy->left = root;
        if(deleteTraversal(root,target))dummy->left = nullptr;
        return dummy->left;
    }
};
