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
    vector<string> ans;
    void traverse(TreeNode* root, string path){
        if(root==nullptr){
            return;
        }
        path = path + "->" + to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(path);
        }
        traverse(root->left,path);
        traverse(root->right,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string start = "";
        start += to_string(root->val);
        if(root->left==nullptr && root->right==nullptr)ans.push_back(start);
        traverse(root->left,start);
        traverse(root->right,start);
        return ans;
    }
};
