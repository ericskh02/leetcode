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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            bool notnull = false;
            int last = 0;
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==nullptr) continue;
                notnull = true;
                last = curr->val;
                q.push(curr->left);
                q.push(curr->right);
            }
            if(notnull){
                ans.push_back(last);
            }
        }
        return ans;
    }
};
