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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int mid = find(inorder.begin(),inorder.end(),postorder[postorder.size()-1]) - inorder.begin();
        vector<int> inorderLeft(&inorder[0],&inorder[mid]);
        vector<int> postorderLeft(&postorder[0],&postorder[mid]);
        root->left = buildTree(inorderLeft,postorderLeft);
        if(mid+1<inorder.size()){
            vector<int> inorderRight(&inorder[mid+1],&inorder[inorder.size()]);
            vector<int> postorderRight(&postorder[mid],&postorder[postorder.size()-1]);
            root->right = buildTree(inorderRight,postorderRight);
        }
        return root;
    }
};
