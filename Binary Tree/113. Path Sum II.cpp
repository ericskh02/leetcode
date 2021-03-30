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
    void traversal(TreeNode* root, int& targetSum, int& sum, vector<int>& route){
        sum += root->val;
        route.push_back(root->val);
        if(sum == targetSum && root->left==nullptr && root->right==nullptr) ans.emplace_back(route);
        if(root->left!=nullptr){
            traversal(root->left,targetSum,sum,route);
        }
        if(root->right!=nullptr){
            traversal(root->right,targetSum,sum,route);
        }
        sum -= root->val;
        route.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return ans;
        vector<int> route;
        int sum = 0;
        traversal(root,targetSum,sum,route);
        return ans;
    }
};
