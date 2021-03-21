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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()>0){
            TreeNode* temp = s.top();
            s.pop();
            if(temp==nullptr) continue;
            ans.push_back(temp->val);
            s.push(temp->right);
            s.push(temp->left);
        }
        return ans;
    }
};
