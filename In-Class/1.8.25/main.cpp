#include <vector>

class Solution {
public:
    std::vector<int> nodes;

    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return nodes;
        }
        inorderTraversal(root->left);
        nodes.push_back(root->val);
        inorderTraversal(root->right);

        return nodes;
    }

};

class Solution {
public:
    std::vector<int> nodes;

    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return nodes;
        }

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        nodes.push_back(root->val);
        return nodes;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
