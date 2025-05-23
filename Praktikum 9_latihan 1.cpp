#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (!node->left && !node->right)
            return depth;

        if (node->left)
            q.push({node->left, depth + 1});
        if (node->right)
            q.push({node->right, depth + 1});
    }
    return 0;
}

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i >= nodes.size()) break;

        if (nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    vector<int> input;
    int val;

    cout << "Masukkan node level-order (gunakan -1 untuk null), akhiri dengan -999:\n";
    cout << "Contoh input : 3 9 20 -1 -1 15 7 -999 \n";
    while (cin >> val && val != -999) {
        input.push_back(val);
    }

    TreeNode* root = buildTree(input);
    cout << "Batas kedalaman minimum: " << minDepth(root) << endl;

    return 0;
}
