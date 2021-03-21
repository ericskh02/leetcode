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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            vector<int> levelval;
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp==nullptr) continue;
                levelval.push_back(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            if(levelval.size()>0){
                ans.insert(ans.begin(),levelval);
            }
        }
        return ans;
    }
};
