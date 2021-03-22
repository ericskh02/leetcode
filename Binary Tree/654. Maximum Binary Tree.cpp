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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            mx = max(mx,nums[i]);
        }
        int index = find(nums.begin(),nums.end(),mx) - nums.begin();
        TreeNode* root = new TreeNode(nums[index]);
        if(0<=index-1){
            vector<int> left (&nums[0],&nums[index]);
            root->left = constructMaximumBinaryTree(left);
        }
        if(index+1<=nums.size()-1){
            vector<int> right (&nums[index+1],&nums[nums.size()]);
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};
