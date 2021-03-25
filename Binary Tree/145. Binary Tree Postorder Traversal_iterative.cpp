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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*,bool>> s;
        s.push({root,false});
        while(s.size()>0){
            pair<TreeNode*,bool> curr = s.top();
            s.pop();
            if(curr.first==nullptr){
                continue;
            }
            if(!curr.second){
                s.push({curr.first,true});
                s.push({curr.first->right,false});
                s.push({curr.first->left,false});
            } else {
                ans.push_back(curr.first->val);
            }
        }
        return ans;
    }
};
