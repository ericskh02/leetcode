/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void traversal(Node* root){
        if(root==nullptr) return;
        vector<Node*> children = root->children;
        for(int i = 0;i<children.size();i++){
            traversal(children[i]);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        traversal(root);
        return ans;
    }
};
