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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            int tempsum = 0;
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==nullptr) continue;
                tempsum += curr->val;
                q.push(curr->left);
                q.push(curr->right);
            }
            if(tempsum>0) sum = tempsum;
        }
        return sum;
    }
};
