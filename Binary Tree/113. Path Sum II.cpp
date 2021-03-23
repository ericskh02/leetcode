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
    vector<vector<int>> ans;
    void traversal(TreeNode* root, vector<int> route, int sum, int targetSum){
        route.push_back(root->val);
        sum += root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==targetSum) ans.push_back(route);
        }
        if(root->left!=nullptr){
            traversal(root->left,route,sum,targetSum);
        }
        if(root->right!=nullptr){
            traversal(root->right,route,sum,targetSum);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> route;
        if(root==nullptr) return ans;
        traversal(root,route,0,targetSum);
        return ans;
    }
};
