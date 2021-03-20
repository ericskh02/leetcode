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
    TreeNode* ans = nullptr;
    void traversal(TreeNode* root,int target){
        if(root==nullptr)return;
        if(root->val == target){
            ans = root;
        }
        traversal(root->left,target);
        traversal(root->right,target);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        traversal(root,val);
        return ans;
    }
};
