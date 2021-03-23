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
    void traversal(TreeNode* root, int sum){
        if(root->left == nullptr && root->right == nullptr){
            ans += sum*10+root->val;
            return;
        }
        if(root->left!=nullptr){
            traversal(root->left,sum*10+root->val);
        }
        if(root->right!=nullptr){
            traversal(root->right,sum*10+root->val);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        traversal(root,0);
        return ans;
    }
};
