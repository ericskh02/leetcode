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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        int mx = INT_MIN;
        int level = 1;
        while(q.size()>0){
            int size = q.size();
            int temp = 0;
            bool found = false;
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==nullptr) continue;
                found = true;
                temp+=curr->val;
                q.push(curr->left);
                q.push(curr->right);
            }
            if(found && temp>mx){
                ans = level;
                mx = temp;
            }
            level++;
        }
        return ans;
    }
};
