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
    int maxDepth(Node* root) {
        if(root==nullptr)return 0;
        int depth = 0;
        queue<Node*> q;
        q.push(root);
        int ans = 0;
        while(q.size()>0){
            int size = q.size();
            for(int i = 0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                if(temp==nullptr) continue;
                ans = depth;
                vector<Node*> children = temp->children;
                for(int i = 0;i<children.size();i++){
                    q.push(children[i]);
                }
            }
            depth++;
        }
        return ans+1;
    }
};
