/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            for(int i = 0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                if(curr==nullptr) continue;
                Node* right = q.front();
                if(i<size-1) curr->next = right;
                else curr->next = nullptr;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return root;
    }
};
