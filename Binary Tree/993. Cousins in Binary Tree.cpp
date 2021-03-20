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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int s = q.size();
            int foundX = -1;
            int foundY = -1;
            for(int i = 0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp==nullptr)continue;
                cout<<temp->val<<" ";
                if(temp->val==x)foundX = i;
                if(temp->val==y)foundY = i;
                q.push(temp->left);
                q.push(temp->right);
            }
            cout<<endl;
            if(foundX!=-1 && foundY!=-1 && (abs(foundX-foundY)>1||max(foundX,foundY)%2==0))return true;
            if(foundX!=-1 || foundY!=-1)return false;
        }
        return false;
    }
};
