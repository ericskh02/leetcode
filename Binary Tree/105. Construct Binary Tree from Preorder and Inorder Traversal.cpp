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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = find(inorder.begin(),inorder.end(),root->val) - inorder.begin();
        if(preorder.size()>1){
            vector<int> preorderLeft (&preorder[1],&preorder[mid+1]);
            vector<int> inorderLeft (&inorder[0],&inorder[mid]);
            root->left = buildTree(preorderLeft,inorderLeft);
        }
        if(preorder.size()>mid+1){
            vector<int> preorderRight (&preorder[mid+1],&preorder[preorder.size()]);
            vector<int> inorderRight (&inorder[mid+1],&inorder[inorder.size()]);
            root->right = buildTree(preorderRight,inorderRight);
        }
        return root;
    }
};
