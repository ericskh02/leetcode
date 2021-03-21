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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            double sum = 0;
            int n = 0;
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp==nullptr) continue;
                sum+=temp->val;
                n++;
                q.push(temp->left);
                q.push(temp->right);
            }
            if(n>0)ans.push_back(sum/n);
        }
        return ans;
    }
};
