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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()<=0) return nullptr;
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(mid-1 >= 0){
            vector<int> left(&nums[0],&nums[mid]);
            root->left = sortedArrayToBST(left);
        }
        if(mid+1 < nums.size()){
            vector<int> right(&nums[mid+1],&nums[nums.size()]);
            root->right = sortedArrayToBST(right);
        }
        return root;
    }
};
