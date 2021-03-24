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
    void traversal(TreeNode* root, int& sum,vector<int> combine){
        if(root==nullptr) return;
        for(int i = 0;i<combine.size();i++){
            combine[i] += root->val;
            if(combine[i]==sum) ans++;
        }
        if(root->val==sum) ans++;
        combine.push_back(root->val);
        traversal(root->left,sum,combine);
        traversal(root->right,sum,combine);
    }
    int pathSum(TreeNode* root, int sum) {
        vector<int> newV;
        traversal(root,sum,newV);
        return ans;
    }
};
