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
    TreeNode* ans;
    vector<int> traversal(TreeNode* root,vector<int>& deepestLeaves){
        vector<int> combine;
        if(root==nullptr) return combine;
        vector<int> left = traversal(root->left,deepestLeaves);
        vector<int> right = traversal(root->right,deepestLeaves);
        if(find(deepestLeaves.begin(),deepestLeaves.end(),root->val)!=deepestLeaves.end()){
            combine.push_back(root->val);
        }
        combine.insert(combine.end(),left.begin(),left.end());
        combine.insert(combine.end(),right.begin(),right.end());
        sort(combine.begin(),combine.end());
        if(combine==deepestLeaves){
            ans = root;
            vector<int> empty;
            return empty;
        }
        return combine;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<int> deepestLeaves;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            vector<int> leaves;
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==nullptr) continue;
                leaves.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            if(leaves.size()>0){
                deepestLeaves = leaves;
            }
        }
        sort(deepestLeaves.begin(),deepestLeaves.end());
        traversal(root,deepestLeaves);
        return ans;
    }
};
