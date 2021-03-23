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
    bool checkSubtree(TreeNode* s, TreeNode* t){
        if(s==nullptr && t==nullptr) return true;
        if(s==nullptr || t==nullptr) return false;
        return checkSubtree(s->left,t->left) && checkSubtree(s->right,t->right) && s->val == t->val;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr) return false;
        if(s->val == t->val){
            return checkSubtree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
        }
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};
