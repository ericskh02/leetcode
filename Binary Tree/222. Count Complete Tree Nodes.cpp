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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        TreeNode* curr;
        while(q.size()>0){
            int size = q.size();
            for(int i = 0;i<size;i++){
                curr = q.front();
                q.pop();
                if(curr==nullptr){
                    break;
                }
                cnt++;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return cnt;
    }
};
