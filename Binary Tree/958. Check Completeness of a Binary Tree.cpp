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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int firstnull= -1;
        int level = 0;
        while(q.size()>0){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==nullptr){
                    if(firstnull==-1){
                        firstnull = level;
                    }
                    continue;
                }
                if(firstnull!=-1) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
            level++;
        }
        return true;
    }
};
