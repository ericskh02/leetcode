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
    string tree2str(TreeNode* t) {
        if(t==nullptr) return "";
        string leftstr = tree2str(t->left);
        string rightstr = tree2str(t->right);
        string temp = "";
        temp+=to_string(t->val);
        if(leftstr.size()>0 || rightstr.size()>0){
            temp+="("+leftstr+")";
        }
        if(rightstr.size()>0){
            temp+="("+rightstr+")";
        }
        return temp;
    }
};
