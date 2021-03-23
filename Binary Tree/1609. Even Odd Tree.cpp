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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int step = 0;
        while(q.size()>0){
            int size = q.size();
            int temp = -1;
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==nullptr) {
                    continue;
                }
                if(temp!=-1){
                    if(step%2==0 && curr->val<=temp){
                        return false;
                    } else if(step%2==1 && curr->val>=temp){
                        return false;
                    }
                }
                if(step%2==0 && curr->val%2==0){
                    return false;
                } else if(step%2==1 && curr->val%2==1){
                    return false;
                }
                temp = curr->val;
                q.push(curr->left);
                q.push(curr->right);
            }
            step++;
        }
        return true;
    }
};
