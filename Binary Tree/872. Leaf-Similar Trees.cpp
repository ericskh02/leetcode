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
    vector<int> root1leaf;
    vector<int> root2leaf;
    void traverse(TreeNode* root, vector<int>* rootleaf){
        if(root==nullptr) return;
        traverse(root->left,rootleaf);
        traverse(root->right,rootleaf);
        if(root->left==nullptr && root->right==nullptr){
            rootleaf->push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {    
        traverse(root1,&root1leaf);
        traverse(root2,&root2leaf);
        if(root1leaf.size()!=root2leaf.size())return false;
        for(int i = 0;i<root1leaf.size();i++){
            if(root1leaf[i]!=root2leaf[i])return false;
        }
        return true;
    }
};
