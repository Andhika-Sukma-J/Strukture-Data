#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->val <= minVal || root->val >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->val) &&
           isBSTUtil(root->right, root->val, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(6);

    if (isBST(root))
        cout << "BST" << endl;
    else
        cout << "Bukan BST" << endl;

    return 0;
}


Bukan BST


