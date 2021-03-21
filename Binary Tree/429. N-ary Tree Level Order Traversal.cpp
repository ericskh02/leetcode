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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            vector<int> levelans;
            for(int i = 0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                if(temp==nullptr) continue;
                levelans.push_back(temp->val);
                vector<Node*> children = temp->children;
                for(int j = 0;j<children.size();j++){
                    q.push(children[j]);
                }
            }
            if(levelans.size()>0)ans.push_back(levelans);
        }
        return ans;
    }
};
