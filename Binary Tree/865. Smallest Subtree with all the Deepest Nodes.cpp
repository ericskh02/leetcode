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
    int maxdistance = 0;
    int maxnodecount = 0;
    TreeNode* ans = nullptr;
    void findDistance(TreeNode* root, int distance){
        if(root==nullptr){
            return;
        }
        distance++;
        findDistance(root->left,distance);
        findDistance(root->right,distance);
        if(distance>maxdistance){
            maxdistance = distance;
            maxnodecount = 0;
        }
        if(distance==maxdistance) maxnodecount++;
                
    }
    int findSubtree(TreeNode* root, int distance){
        if(root==nullptr) return 0;
        distance++;
        int found = findSubtree(root->left,distance) + findSubtree(root->right,distance);
        if(distance == maxdistance) found++;
        if(ans==nullptr && found>=maxnodecount){
            ans = root;
            return 0;
        }
        return found;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        findDistance(root,-1);
        findSubtree(root,-1);
        return ans;
    }
};
