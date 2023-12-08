/*
You are given a perfect binary tree where all leaves are on 
the same level, and every parent has two children. The binary
tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be
set to NULL.

Initially, all next pointers are set to NULL.
*/

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
    void connect(Node * r1, Node * r2){
        while (r1){
            r1->next = r2;
            r1 = r1->right;
            r2 = r2->left;
        }
    }
    Node* connect(Node* root) {
        if (!root) return nullptr;
        if (root->left) {
            connect(root->left, root->right);
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
