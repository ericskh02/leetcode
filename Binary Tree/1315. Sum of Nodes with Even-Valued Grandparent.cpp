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
    int ans = 0;
    void traversal(TreeNode* curr, bool grandParentEven, bool parentEven){
        if(curr==nullptr){
            return;
        }
        if(grandParentEven){
            ans += curr->val;
        }
        bool currEven = (curr->val)%2 == 0;
        traversal(curr->left,parentEven,currEven);
        traversal(curr->right,parentEven,currEven);
    }
    int sumEvenGrandparent(TreeNode* root) {
        traversal(root,false,false);
        return ans;
    }
};
