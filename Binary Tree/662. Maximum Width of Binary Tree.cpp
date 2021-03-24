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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()>0){
            int size = q.size();
            ans = max(ans,q.back().second - q.front().second + 1);
            for(int i = 0;i<size;i++){
                pair<TreeNode*,long long> curr = q.front();
                q.pop();
                if(curr.first==nullptr) continue;
                if(curr.first->left!=nullptr){
                    q.push({curr.first->left,curr.second*2+1});
                }
                if(curr.first->right!=nullptr){
                    q.push({curr.first->right,curr.second*2+2});
                }
            }
        }
        return ans;
    }
};
